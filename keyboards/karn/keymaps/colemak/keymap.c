// Copyright 2023 Robert Mills (@robcmills)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

// Tap Dance declarations
enum {
    TD_F1_F11,
    TD_F2_F12,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for F1, twice for F11
    [TD_F1_F11] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F11),
    [TD_F2_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F12),
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_Z): // Special case for Shift
            return true; // Immediately select the hold action when another key is pressed.
        case SFT_T(KC_ESC):
            return true;
        default:
            return false; // Do not select the hold action when another key is pressed.
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    // default (colemak)
    [0] = LAYOUT(
                       KC_Q,       KC_W,       KC_F,       KC_P,       KC_G,                        KC_J,  KC_L,       KC_U,          KC_Y,         KC_SCLN,
        HYPR_T(KC_TAB),KC_A,       KC_R,       KC_S,       KC_T,       KC_D,                        KC_H,  KC_N,       KC_E,          KC_I,         KC_O,           HYPR_T(KC_ENT),
                       SFT_T(KC_Z),CTL_T(KC_X),ALT_T(KC_C),CMD_T(KC_V),KC_B,                        KC_K,  CMD_T(KC_M),ALT_T(KC_COMM),CTL_T(KC_DOT),RSFT_T(KC_SLSH),
                                                           MO(1),      SFT_T(KC_ESC),MO(3), KC_BSPC,KC_SPC,MO(2)
    ),

    // symbols
    [1] = LAYOUT(
                 KC_BSLS, KC_GRV,  KC_QUOT, KC_DQT,  KC_LCBR,                    KC_RCBR, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
                 _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______,
                                            _______, _______, _______,  KC_DEL,  _______, _______
    ),

    // nav
    [2] = LAYOUT(
                 _______, KC_Q,      _______,   _______,   KC_VOLU,                    _______, _______, _______, KC_SCLN, _______,
        _______, C(KC_UP),C(KC_DOWN),G(KC_GRV), G(KC_TAB), KC_VOLD,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _______,
                 _______, _______,   _______,   _______,   KC_MUTE,                    _______, _______, _______, _______, _______,
                                                _______,   _______, _______,  _______, _______, _______
    ),

    // numbers
    [3] = LAYOUT(
                 TD(TD_F1_F11), TD(TD_F2_F12), KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        _______, KC_1,          KC_2,          KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
                 _______,       _______,       _______, _______, _______,                    _______, _______, _______, _______, _______,
                                                        _______, _______, _______,  _______, _______, _______
    )
};
