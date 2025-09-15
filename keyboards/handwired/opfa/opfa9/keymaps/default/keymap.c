// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/*
 * Hit Mute, Vol-, Vol+ to drop into Boot mode
 */

const uint16_t PROGMEM qk_boot_combo[] = {KC_KB_MUTE, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, COMBO_END};

combo_t key_combos[] = {
    COMBO(qk_boot_combo, QK_BOOT),
};

enum custom_keycodes {
    MACRO_SEL_ALL = SAFE_RANGE,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_SEL_ALL:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a"));
            } else {
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───────┬──────┬───────┐
     * │ Mute  │ Vol- │  Vol+ │
     * ├───────┼──────┼───────┤
     * │  <<   │   >  │   >>  │
     * ├───────┼──────┼───────┤
     * │ S_ALL │ COPY │ PASTE │
     * └───────┴──────┴───────┘
     */
    [0] = LAYOUT_ortho_3x3(
        KC_KB_MUTE,             KC_KB_VOLUME_DOWN,      KC_KB_VOLUME_UP,
        KC_MEDIA_PREV_TRACK,    KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_NEXT_TRACK,
        MACRO_SEL_ALL,                 KC_COPY,                KC_PASTE
    )
};
