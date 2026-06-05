/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100

#define COMBO_TERM 150 // ms
#define COMBO_VARIABLE_LEN
#define COMBO_COUNT 9

// split fixes
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_USB_TIMEOUT_POLL 10
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000
#define MASTER_LEFT     // or #define MASTER_RIGHT if you always plug USB into the right half
#define SPLIT_MAX_CONNECTION_ERRORS 10    // Default, increase if slave drops often
#define SPLIT_CONNECTION_CHECK_TIMEOUT 500
#define FORCED_SYNC_THROTTLE_MS 100
#define SPLIT_TRANSPORT_MIRROR          // Mirror matrix to slave (good for RGB/layer reactions)
#define SPLIT_LAYER_STATE_ENABLE        // Sync layers between halves
#define SPLIT_LED_STATE_ENABLE          // Sync Caps/Num/Scroll lock LEDs
#define SPLIT_MODS_ENABLE               // Sync modifier state
#define EE_HANDS          // This stores handedness in EEPROM — very reliable for Corne
#define MASTER_LEFT       // Change to MASTER_RIGHT if you plug USB into the right half
#define SPLIT_USB_DETECT
// end split fixes

#define RGB_MATRIX_SLEEP
#define RGB_DISABLE_TIMEOUT 300000 // ms
#define RGB_MATRIX_TIMEOUT 300000 // ms
#undef DISABLE_RGB_MATRIX_TIMEOUT


#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
