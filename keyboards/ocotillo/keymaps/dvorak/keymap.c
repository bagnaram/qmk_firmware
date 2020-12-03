/* Copyright 2020 Matt Bagnara
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _DVORAK,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_DVORAK] = LAYOUT(
        KC_ESCAPE, KC_1,      KC_2,      KC_3,     KC_4,    KC_5,  KC_6,     KC_7,    KC_8,    KC_9,  KC_0,    KC_LBRACKET,   KC_RBRACKET,   KC_BSPACE,                  KC_DEL,
        KC_TAB,    KC_QUOTE,  KC_COMMA,  KC_DOT,   KC_P,    KC_Y,  KC_F,     KC_G,    KC_C,    KC_R,  KC_L,    KC_SLASH,      KC_EQUAL,      KC_BSLASH,                  KC_GRAVE,
        KC_CAPS,   KC_A,      KC_O,      KC_E,     KC_U,    KC_I,  KC_D,     KC_H,    KC_T,    KC_N,  KC_S,    KC_MINUS,      KC_ENTER,                                  KC_PGUP,
        KC_LSHIFT,            KC_SCOLON, KC_Q,     KC_J,    KC_K,  KC_X,     KC_B,    KC_M,    KC_W,  KC_V,    KC_Z,          KC_RSHIFT,                    KC_UP,       KC_PGDN,
        KC_LCTRL,  KC_LGUI,   KC_LALT,                             KC_SPACE,                          KC_RALT, MO(_FN),                      KC_LEFT,       KC_DOWN,     KC_RIGHT
    ),
    [_FN] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
