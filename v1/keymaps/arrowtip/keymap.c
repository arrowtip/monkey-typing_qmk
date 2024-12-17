// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define DE_AE RALT(KC_Q)
#define DE_OE RALT(KC_P)
#define DE_UE RALT(KC_Y)
#define DE_SS RALT(KC_S)

#define TRN KC_TRNS

enum layer_names {
    BASE_LAYER = 0,
    FN_LAYER,
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE_LAYER] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [FN_LAYER] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌──────┬───┬───┬───┬───┬───┬───┐                     ┌───┬───┬───┬───┬───┬───┬──────┐
     * │ `    │ 1 │ 2 │ 3 │ 4 │ 5 │ = │                     │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │    - │
     * ├──────┼───┼───┼───┼───┼───┼───┤                     ├───┼───┼───┼───┼───┼───┼──────┤
     * │ Tab  │ Q │ W │ E │ R │ T │ = │                     │ Y │ Y │ U │ I │ O │ P │    \ │
     * ├──────┼───┼───┼───┼───┼───┤   │                     │   ├───┼───┼───┼───┼───┼──────┤
     * │Escape│ A │ S │ D │ F │ G ├───┤                     ├───┤ H │ J │ K │ L │ ; │    ' │
     * ├──────┼───┼───┼───┼───┼───┤   │                     │   ├───┼───┼───┼───┼───┼──────┤
     * │Shift │ Z │ X │ C │ V │ B │ B │                     │ N │ N │ M │ , │ . │ / │ Shift│
     * └──┬───┼───┼───┼───┼───┼───┴───┘ ┌───┬───┐ ┌───┬───┐ └───┴───┼───┼───┼───┼───┼───┬──┘
     *    │Ctl│F4 │F5 │GUI│Alt│         │ C │ V │ │Alt│ A │         │ ← │ ↓ │ ↑ │ → │GUI│
     *    └───┴───┴───┴───┴───┘     ┌───┼───┼───┤ ├───┼───┼───┐     └───┴───┴───┴───┴───┘
     */
    [BASE_LAYER] = LAYOUT_iso(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_PAUS, KC_LCTL, KC_ESC,  KC_SPC,  MO(FN_LAYER),       KC_ENT,   KC_BSPC, KC_LGUI, KC_LALT, KC_RGUI
    ),
    [FN_LAYER] = LAYOUT_iso(
        TRN,        TRN,        TRN,        TRN,        TRN,        KC_SLEP,                                      TRN,        TRN,        TRN,        TRN,        TRN,        KC_EQL,
        TRN,        TRN,        TRN,        TRN,        TRN,        TRN,                                      TRN,        DE_UE,      TRN,        DE_OE,      TRN,        TRN,
        TRN,        DE_AE,      DE_SS,      TRN,        TRN,        TRN,                                      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    TRN,        TRN,
        TRN,        TRN,        TRN,        TRN,        TRN,        TRN,                                      TRN,        TRN,        KC_LBRC,    KC_RBRC,    TRN,        TRN,
                                TRN,        TRN,        TRN,        TRN,        TRN,                TRN,      KC_DEL,        TRN,        TRN,        KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
