# `crkbd_qmk`
> My custom keymap for QMK-enabled [foostan Corne V4.1's](https://github.com/foostan/crkbd/).

![photo of keyboard](alt/image1.jpg)
More images in the `alt/` folder.

## Layout:
![layout image](alt/layout.png)
> Combos are annoying on the keymap drawer so here is a list of QMK combos, generated using `make combos`

```bash
KC_D, KC_F, = KC_GRV
KC_Z, KC_X, = S(KC_9)
KC_X, KC_C, = S(KC_LBRC)
KC_C, KC_V, = KC_LBRC
KC_J, KC_K, = KC_BSL
KC_DOT, KC_SLSH, = S(KC_0)
KC_COMM, KC_DOT, = KC_RBRC
KC_M, KC_COMM, = S(KC_RBRC)
KC_SPC, KC_ENT, = KC_CAPS
```

## Flashing
QMK does not work correctly with my system, specifically QMK flashing. To remedy this I've written a custom script (`src/flash`) that correctly flashes the new firmware to the board."
<br></br>
To flash the firmware just run the following:
```
make flash
```
You will be prompted for sudo at one point, please ensure you have read the `Makefile` and the `src/flash` file.

## Thoughts
I've been using this keyboard for little over a month and I've had zero problems up until now. I've just found that I accidentally hotplugged the board, this occurs when you remove the connection TRS/TRRS cable while one side of the board if powered. This action damages the MCU of the RP2040 chip irrepairably which means the board is out of service until I obtain a new PCB. This is a rather common issue with this keyboard and I can confirm that this issue is entirely my fault, I'd been flashing QMK firmware the evening that it happened and I must have been to hasty to remove the connection cable.
<br><br>
Even though this board is broken after a very minor action, I still intend on maining this keyboard. It is the ONLY 46-key budget keyboard that works for me. For the 6 years prior to purchasing this keyboard, I mained a RK61. I can safley say I will not be purchasing another non-split non-ergo keyboard. After only one month of using the Corne, my wrist pain has completly disapeared..
<br></br>
So.<br>
All in all, I would still recommend this board, even with its clear hardware flaws.
