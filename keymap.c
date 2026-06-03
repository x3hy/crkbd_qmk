#include QMK_KEYBOARD_H

enum layers { _BASE, _SYM, _NAV, _L3, _L4, _L5 };

enum custom_keycodes {
  WIN0 = SAFE_RANGE,
  WIN1,
  WIN2,
  WIN3,
  WIN4,
  WIN5,
  WIN6,
  WIN7,
  WIN8,
  WIN9
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  switch (keycode) {
  case WIN0:
    tap_code16(LGUI(KC_0));
    return false;
  case WIN1:
    tap_code16(LGUI(KC_1));
    return false;
  case WIN2:
    tap_code16(LGUI(KC_2));
    return false;
  case WIN3:
    tap_code16(LGUI(KC_3));
    return false;
  case WIN4:
    tap_code16(LGUI(KC_4));
    return false;
  case WIN5:
    tap_code16(LGUI(KC_5));
    return false;
  case WIN6:
    tap_code16(LGUI(KC_6));
    return false;
  case WIN7:
    tap_code16(LGUI(KC_7));
    return false;
  case WIN8:
    tap_code16(LGUI(KC_8));
    return false;
  case WIN9:
    tap_code16(LGUI(KC_9));
    return false;
  }

  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x6_3_ex2(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_MINS, KC_EQL, KC_Y, KC_U, KC_I,
        KC_O, KC_P, KC_BSPC,

        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_TAB, KC_SPC, KC_H, KC_J, KC_K,
        KC_L, KC_SCLN, KC_QUOT,

        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,
        KC_SLSH, LT(2, KC_NO),

        LT(1, KC_NO), KC_LGUI, KC_SPC, KC_ENT, KC_LSFT, LT(1, KC_NO)),

    [_SYM] = LAYOUT_split_3x6_3_ex2(
        KC_GRV, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_LBRC, KC_RBRC,
        S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_BSPC,

        KC_LSFT, KC_1, KC_2, KC_3, KC_4, KC_5, S(KC_LBRC), S(KC_RBRC), KC_6,
        KC_7, KC_8, KC_9, KC_0, KC_BSLS,

        KC_LCTL, WIN1, WIN2, WIN3, WIN4, WIN5, WIN6, WIN7, WIN8, WIN9, WIN0,
        S(KC_BSLS),

        KC_NO, KC_LGUI, KC_SPC, KC_ENT, KC_LSFT, KC_NO),

    [_NAV] = LAYOUT_split_3x6_3_ex2(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_BSPC, KC_F12,
        KC_F11, KC_F10, KC_F9, KC_F8, KC_F7,

        KC_LSFT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, RM_NEXT, RM_TOGG, KC_MFFD,
        KC_MRWD, KC_UP, KC_RGHT, KC_UP, KC_DOWN, KC_LEFT,

        KC_LCTL, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, RM_PREV, KC_RGHT, KC_DOWN,
        KC_LEFT, KC_VOLU, KC_VOLD, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

    [_L3] =
        LAYOUT_split_3x6_3_ex2(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

    [_L4] =
        LAYOUT_split_3x6_3_ex2(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

    [_L5] =
        LAYOUT_split_3x6_3_ex2(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)

};
