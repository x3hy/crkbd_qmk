# `crkbd_qmk`
> My custom keymap for QMK-enabled foostan Corne V4.1's.

Because of the Redhat cuck-ware known as `udevd`, QMK does not work correctly with my system and is unable to locate and mount the RPI device in order to flash firmware. To remedy this, I've written a custom recipe in the `Makefile` of this project, that will locate, mount and flash the keyboard. To ensure safety of your machines HID devices, please ensure that only one device is listed as "`RPI-RP2`". Please read the "`flash`" recipe in the `Makefile`, ensure that this behavior will not break any other HID devices on your machine.

![photo of keyboard](layout/photo1.jpg)

![photo of keyboard](layout/photo2.jpg)

## Layout:
![layout image](layout/layout.png)

### Combos:
> Combos are annoying on the keymap drawer so here is a list of QMK combos, generated using `make combos`


## Installing
To flash the firmware just run the following:
```
make flash
```
You will be prompted for sudo at one point, please ensure you have read the `Makefile`.
<br><br>

To simply compile, you can run the following:
```
make compile
```

This will also move the compiled uf2 file to the current directory.
