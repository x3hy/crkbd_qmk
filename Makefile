QMK_KP     = crkbd
QMK_VR     = rev4_1
QMK_VA     = standard
QMK_KB     = $(QMK_KP)/$(QMK_VR)/$(QMK_VA)
QMK_KM     = x3hy
QMK_N      = $(QMK_KP)_$(QMK_VR)_$(QMK_VA)_$(QMK_KM).uf2
DEV_NAME   = RPI-RP2
MOUNT_PATH = /run/media/_3hy/$(DEV_NAME)

all: write compile

write: $(QMK_KM)/config.h $(QMK_KM)/keymap.c $(QMK_KM)/rules.mk
	-rm ~/qmk_firmware/keyboards/$(QMK_KP)/keymaps/$(QMK_KM) -r
	qmk new-keymap -kb $(QMK_KB) -km $(QMK_KM)
	cp $(QMK_KM)/* ~/qmk_firmware/keyboards/$(QMK_KP)/keymaps/$(QMK_KM)

compile: write
	qmk compile -kb $(QMK_KB) -km $(QMK_KM) -e VERBOSE=true -j $(shell nproc)
	@echo "Moving uf2 file to current dir"
	cp ~/qmk_firmware/$(QMK_N) .

c2json: write $(QMK_KM)/keymap.c
	qmk c2json -kb $(QMK_KB) -km $(QMK_KM) $(QMK_KM)/keymap.c > layout/layout.json

combo: combo.sh
	./$^ $(QMK_KM)/keymap.c

log_comp:
	make compile 2>&1 | tee log

format:
	clang-format keymap.c > tmp
	mv keymap.c /tmp
	mv tmp keymap.c

.ONESHELL:
flash: write
	# Surpass udev issues by giving user root perms
	echo "Allowing access to:"
	find /dev/hidraw* | while read line; do
		sudo chown $$USER $$line;
		echo -n "$$line : ";
	done
	echo "";
	# Unmount keyboard if already mounted:
	if [ -e $(MOUNT_PATH) ]; then
		-sudo umount $(MOUNT_PATH) 2>/dev/null;
		-sudo rm -r $(MOUNT_PATH) 2>/dev/null;
	fi
	# Create the new mount dir
	-sudo mkdir -p $(MOUNT_PATH);
	# Loop through each drive partition
	echo "Locating device $(DEV_NAME)";
	lsblk -lno NAME,TYPE | awk '$$2=="part" {print "/dev/"$$1}' |\
		while read dev; do
		# Locate the device's path by name
		udevadm info --query=property --name=$$dev | grep "ID_SERIAL=" |\
			while read info; do
			case "$$info" in
				*RPI_RP2*)
					# Mount the device to the given mount path
					echo "";
					echo "Found $(DEV_NAME) at $$dev"
					sudo mount -o uid=$(shell id -u),gid=$(shell id -u),umask=0022 $$dev $(MOUNT_PATH)
					# Qmk will be able to find the device now
					qmk flash -kb $(QMK_KB) -km $(QMK_KM) -j $(shell nproc)
					sudo umount $(MOUNT_PATH)
				;;
				*) echo -n "$$dev : "
				;;
			esac
		done
	done
	echo ""
	echo "If QMK did not start then the device was not found, ensure it is in bootloader mode."

