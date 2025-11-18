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

// Tap-hold tuning for reliable Mod-Tap behavior (e.g., CTL_T(KC_ESC))
// Increase tapping term a bit to help distinguish quick taps from holds.
// Adjust to taste (150–220ms is common for home-row mods).
//#define QUICK_TAP_TERM 0
#define TAPPING_TERM 200

// Combo timing window (uncomment to customize)
// #define COMBO_TERM 200

// Prefer hold when another key is pressed while holding a Mod-Tap.
// This makes chords like Ctrl+S followed by Ctrl+W reliable when using CTL_T(KC_ESC).
#define HOLD_ON_OTHER_KEY_PRESS

// Ensure that once a Mod-Tap acts as a hold during a chord, releasing it first
// won't send the tap keycode (prevents accidental Esc when rolling off).
#define TAPPING_FORCE_HOLD
