QMK_KP     = crkbd
QMK_VR     = rev4_1
QMK_VA     = standard
QMK_KM     = x3hy
QMK_KB     = $(QMK_KP)/$(QMK_VR)/$(QMK_VA)
QMK_UF2    = $(QMK_KP)_$(QMK_VR)_$(QMK_VA)_$(QMK_KM).uf2
FSH_UF2    = firmware.uf2

# Remove old layout and firmware bin
clean:
	-rm $(FSH_UF2)
	-rm ~/qmk_firmware/keyboards/$(QMK_KP)/keymaps/$(QMK_KM) -r

keymap:
	qmk new-keymap -kb $(QMK_KB) -km $(QMK_KM)

# Generate the firmware bin
$(FSH_UF2): ~/qmk_firmware/keyboards/$(QMK_KP)/keymaps/$(QMK_FM) $(QMK_KM)/config.h $(QMK_KM)/keymap.c $(QMK_KM)/rules.mk
	cp $(QMK_KM)/* ~/qmk_firmware/keyboards/$(QMK_KP)/keymaps/$(QMK_KM)
	#
	qmk compile -kb $(QMK_KB) -km $(QMK_KM) -e VERBOSE=true -j $(shell nproc)
	cp ~/qmk_firmware/$(QMK_UF2) $(FSH_UF2)

# List the combos in keymap.c
combos: src/combos $(QMK_KM)/keymap.c
	./$(firstword $^) $(lastword $^)

# Flash the current keymap.c file to the board
flash: src/flash $(FSH_UF2)
	sudo ./$(firstword $^) $(lastword $^)

# Grant the user permission to hidraw devices
grant: src/grant
	sudo ./$^
