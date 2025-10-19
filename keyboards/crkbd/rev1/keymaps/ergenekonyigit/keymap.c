/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _FIRST,  // (1)
  _SECOND, // (2)
  _THIRD,  // (3)
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* qwerty layer
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |  tab  |   q   |   w   |   e   |   r   |   t   |       |   y   |   u   |   i   |   o   |   p   | bkspc |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * |ctl/esc|   a   |   s   |   d   |   f   |   g   |       |   h   |   j   |   k   |   l   |   ;   |   '   |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | shift |   z   |   x   |   c   |   v   |   b   |       |   n   |   m   |   ,   |   .   |   /   |sft/ent|
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,-----------------------,
 *                         |  opt  |  cmd  | space |       |  (1)  |  (2)  |  (3)  |
 *                         '-----------------------'       '-----------------------'
 */
  [_QWERTY] = LAYOUT_split_3x6_3(
    KC_TAB,         KC_Q,  KC_W,  KC_E,     KC_R,     KC_T,       KC_Y,        KC_U,         KC_I,       KC_O,    KC_P,     KC_BSPC,
    CTL_T(KC_ESC),  KC_A,  KC_S,  KC_D,     KC_F,     KC_G,       KC_H,        KC_J,         KC_K,       KC_L,    KC_SCLN,  KC_QUOT,
    KC_LSFT,        KC_Z,  KC_X,  KC_C,     KC_V,     KC_B,       KC_N,        KC_M,         KC_COMM,    KC_DOT,  KC_SLSH,  RSFT_T(KC_ENT),
                                  KC_LALT,  KC_LGUI,  KC_SPC,     MO(_FIRST),  MO(_SECOND),  MO(_THIRD)
  ),

/* first layer (1)
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |   ~   |   !   |   @   |   #   |   $   |   %   |       |   ^   |   &   |   *   |   (   |   )   | bkspc |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | ctrl  |       |       |       | bri-  | bri+  |       |   -   |   =   |   `   |   [   |   ]   |   \   |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | prev  |ply/pau| next  | mute  | vol-  | vol+  |       |   _   |   +   |   ~   |   {   |   }   |   |   |
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,-----------------------,
 *                         |  opt  |  cmd  | space |       |  (1)  |  (2)  |       |
 *                         '-----------------------'       '-----------------------'
 */
  [_FIRST] = LAYOUT_split_3x6_3(
      KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,     KC_CIRC,  KC_AMPR,      KC_PAST,  KC_LPRN,  KC_RPRN,  KC_BSPC,
      KC_LCTL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BRID,  KC_BRIU,     KC_PMNS,  KC_EQL,       KC_GRV,   KC_LBRC,  KC_RBRC,  KC_BSLS,
      KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,     KC_UNDS,  KC_PPLS,      KC_TILD,  KC_LCBR,  KC_RCBR,  KC_PIPE,
                                    KC_LALT,  KC_LGUI,  KC_SPC,      _______,  MO(_ADJUST),  XXXXXXX
  ),

/* second layer (2)
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |   `   |   1   |   2   |   3   |   4   |   5   |       |   6   |   7   |   8   |   9   |   0   | bkspc |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | ctrl  |   4   |   5   |   6   |       |       |       |  f1   |  f2   |  f3   |  f4   |  f5   |  f6   |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | shift |   7   |   8   |   9   |   0   |       |       |  f7   |  f8   |  f9   |  f10  |  f11  |  f12  |
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,-----------------------,
 *                         |  opt  |  cmd  | space |       |  (1)  |  (2)  |       |
 *                         '-----------------------'       '-----------------------'
 */
  [_SECOND] = LAYOUT_split_3x6_3(
      KC_GRV,   KC_1,  KC_2,  KC_3,     KC_4,     KC_5,        KC_6,     KC_7,         KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_LCTL,  KC_4,  KC_5,  KC_6,     XXXXXXX,  XXXXXXX,     KC_F1,    KC_F2,        KC_F3,   KC_F4,   KC_F5,   KC_F6,
      KC_LSFT,  KC_7,  KC_8,  KC_9,     KC_0,     XXXXXXX,     KC_F7,    KC_F8,        KC_F9,   KC_F10,  KC_F11,  KC_F12,
                              KC_LALT,  KC_LGUI,  KC_SPC,      _______,  MO(_ADJUST),  XXXXXXX
  ),

/* third layer (3)
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |  tab  |       |  up   |       |       |       |       |       |       |       |       |       | bkspc |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | ctrl  | left  | down  | right |       |       |       | left  | down  |  up   | down  |  up   |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | shift |       |       |       |       |       |       |       |       |       | left  | down  | right |
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,-----------------------,
 *                         |  opt  |  cmd  | space |       |       |       |  (3)  |
 *                         '-----------------------'       '-----------------------'
 */
  [_THIRD] = LAYOUT_split_3x6_3(
    KC_TAB,   XXXXXXX,  KC_UP,    XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC,
    KC_LCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_UP,    XXXXXXX,
    KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,
                                  KC_LALT,  KC_LGUI,  KC_SPC,      XXXXXXX,  XXXXXXX,  _______
  ),

/* adjust layer
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |qc_boot|       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |       |
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,-----------------------,
 *                         |       |       |       |       |       |  (2)  |  (3)  |
 *                         '-----------------------'       '-----------------------'
 */
  [_ADJUST] = LAYOUT_split_3x6_3(
      QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                    XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  _______,  _______
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
