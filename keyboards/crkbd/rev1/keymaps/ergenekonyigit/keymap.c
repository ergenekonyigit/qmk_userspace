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
  _SYM,
  _NUM,
  _NAV,
  _FUNC,
};

// --- Combos: press R+T to send '(' on QWERTY layer ---
#ifdef COMBO_ENABLE
enum combos {
  CMB_RT_LPRN,
  CMB_YU_RPRN,
  CMB_FG_LBRC,
  CMB_HJ_RBRC,
  CMB_VB_LCBR,
  CMB_NM_RCBR,
};

// Chord uses base layer keycodes, reference layer will be QWERTY
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};

combo_t key_combos[] = {
  [CMB_RT_LPRN] = COMBO(rt_combo, KC_LPRN),
  [CMB_YU_RPRN] = COMBO(yu_combo, KC_RPRN),
  [CMB_FG_LBRC] = COMBO(fg_combo, KC_LBRC),
  [CMB_HJ_RBRC] = COMBO(hj_combo, KC_RBRC),
  [CMB_VB_LCBR] = COMBO(vb_combo, KC_LCBR),
  [CMB_NM_RCBR] = COMBO(nm_combo, KC_RCBR),
};

// Only allow the combos on the QWERTY layer
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  (void)combo; (void)keycode; (void)record;
  switch (combo_index) {
    case CMB_RT_LPRN:
    case CMB_YU_RPRN:
    case CMB_FG_LBRC:
    case CMB_HJ_RBRC:
    case CMB_VB_LCBR:
    case CMB_NM_RCBR:
      return get_highest_layer(layer_state) == _QWERTY;
  }
  return true;
}
#endif

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
 *                         |  opt  |  cmd  | space |       |  nav  |  sym  |  num  |
 *                         '-----------------------'       '-----------------------'
 */
  [_QWERTY] = LAYOUT_split_3x6_3(
    KC_TAB,         KC_Q,  KC_W,  KC_E,     KC_R,     KC_T,      KC_Y,      KC_U,      KC_I,       KC_O,    KC_P,     KC_BSPC,
    CTL_T(KC_ESC),  KC_A,  KC_S,  KC_D,     KC_F,     KC_G,      KC_H,      KC_J,      KC_K,       KC_L,    KC_SCLN,  KC_QUOT,
    KC_LSFT,        KC_Z,  KC_X,  KC_C,     KC_V,     KC_B,      KC_N,      KC_M,      KC_COMM,    KC_DOT,  KC_SLSH,  RSFT_T(KC_ENT),
                                  KC_LALT,  KC_LGUI,  KC_SPC,    MO(_NAV),  MO(_SYM),  MO(_NUM)
  ),

/* navigation layer
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |  tab  |       |  up   |       |       |       |       |       |       |       |       |       | bkspc |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | ctrl  | left  | down  | right |       |       |       | left  | down  |  up   | down  |       |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | shift |       |       |       |       |       |       |       | left  | down  | right |       | enter |
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,-----------------------,
 *                         |  opt  |  cmd  | space |       | (nav) |       |       |
 *                         '-----------------------'       '-----------------------'
 */
  [_NAV] = LAYOUT_split_3x6_3(
    KC_TAB,   XXXXXXX,  KC_UP,    XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC,
    KC_LCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,  XXXXXXX,
    KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  KC_ENT,
                                  KC_LALT,  KC_LGUI,  KC_SPC,      _______,  XXXXXXX,  XXXXXXX
  ),

/* symbol layer
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |   ~   |   !   |   @   |   #   |   $   |   %   |       |   ^   |   &   |   *   |   (   |   )   | bkspc |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | ctrl  |       |       |       |       |       |       |   -   |   =   |   `   |   [   |   ]   |   \   |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |   _   |   +   |   ~   |   {   |   }   |   |   |
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,-----------------------,
 *                         |  opt  |  cmd  | space |       |       | (sym) |  num  |
 *                         '-----------------------'       '-----------------------'
 */
  [_SYM] = LAYOUT_split_3x6_3(
      KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,     KC_CIRC,  KC_AMPR,  KC_PAST,  KC_LPRN,  KC_RPRN,  KC_BSPC,
      KC_LCTL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     KC_PMNS,  KC_EQL,   KC_GRV,   KC_LBRC,  KC_RBRC,  KC_BSLS,
      KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     KC_UNDS,  KC_PPLS,  KC_TILD,  KC_LCBR,  KC_RCBR,  KC_PIPE,
                                    KC_LALT,  KC_LGUI,  KC_SPC,      XXXXXXX,  _______,  MO(_FUNC),
  ),

/* number layer
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |   `   |   1   |   2   |   3   |   4   |   5   |       |   6   |   7   |   8   |   9   |   0   | bkspc |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | ctrl  |   4   |   5   |   6   |       |       |       |  f1   |  f2   |  f3   |  f4   |  f5   |  f6   |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | shift |   7   |   8   |   9   |   0   |       |       |  f7   |  f8   |  f9   |  f10  |  f11  |  f12  |
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,-----------------------,
 *                         |  opt  |  cmd  | space |       |       |  sym  | (num) |
 *                         '-----------------------'       '-----------------------'
 */
  [_NUM] = LAYOUT_split_3x6_3(
      KC_GRV,   KC_1,  KC_2,  KC_3,     KC_4,     KC_5,        KC_6,     KC_7,         KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_LCTL,  KC_4,  KC_5,  KC_6,     XXXXXXX,  XXXXXXX,     KC_F1,    KC_F2,        KC_F3,   KC_F4,   KC_F5,   KC_F6,
      KC_LSFT,  KC_7,  KC_8,  KC_9,     KC_0,     XXXXXXX,     KC_F7,    KC_F8,        KC_F9,   KC_F10,  KC_F11,  KC_F12,
                              KC_LALT,  KC_LGUI,  KC_SPC,      XXXXXXX,  MO(_FUNC),  _______,
  ),

/* function layer
 * ,-----------------------------------------------,       ,-----------------------------------------------,
 * |       |       |       |       | bri-  | bri+  |       |       |       |       |       |       |qc_boot|
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * |       |       |ms_whll|ms_whld|ms_whlu|ms_whlr|       |kc_left|kc_down| kc_up |kc_rght|       |       |
 * |-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
 * | prev  |ply/pau| next  | mute  | vol-  | vol+  |       |ms_left|ms_down| ms_up |ms_rght|ms_btn1|ms_btn2|
 * '-----------------------------------------------'       '-----------------------------------------------'
 *                         ,-----------------------,       ,-----------------------,
 *                         |  opt  |  cmd  | space |       |       |       |(func) |
 *                         '-----------------------'       '-----------------------'
 */
  [_FUNC] = LAYOUT_split_3x6_3(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BRID,  KC_BRIU,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QK_BOOT,
    XXXXXXX,  XXXXXXX,  MS_WHLL,  MS_WHLD,  MS_WHLU,  MS_WHLR,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,  XXXXXXX,
    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,     MS_LEFT,  MS_DOWN,  MS_UP,    MS_RGHT,  MS_BTN1,  MS_BTN2,
                                  KC_LALT,  KC_LGUI,  KC_SPC,      XXXXXXX,  XXXXXXX,  _______
  )
};
