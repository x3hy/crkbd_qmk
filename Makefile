QMK_KP = "crkbd"
QMK_KB = "$(QMK_KP)/rev4_1/standard"
QMK_KM = "x3hy"
DEV_NAME= RPI-RP2
MOUNT_PATH = "/run/media/_3hy/$(DEV_NAME)/"

all:compile flash

compile:
	qmk compile -kb $(QMK_KB) -km $(QMK_KM)

keymap:
	qmk new-keymap -kb $(QMK_KB) -km $(QMK_KM)
	-rm $(QMK_KM) config.h keymap.c
	ln -s ~/qmk_firmware/keyboards/$(QMK_KP)/keymaps/$(QMK_KM) .
	ln -s $(QMK_KM)/config.h .
	ln -s $(QMK_KM)/keymap.c .

.ONESHELL:
flash:
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
				;;
				*)
					echo -n "$$dev : "
				;;
			esac
		done
	done
	# Qmk will be able to find the device now
	qmk flash -kb $(QMK_KB) -km $(QMK_KM)
