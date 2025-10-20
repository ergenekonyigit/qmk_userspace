## Corne (crkbd rev1) — ergenekonyigit keymap

![keyboard](./keyboard.jpeg)

## Overview

-   Base layout: QWERTY with a home-row Control on the left A position (tap Escape, hold Control).
-   Layers: NAV via LT on Space, plus right-thumb momentary layers for Symbols (1), Numbers (2), Function/Media (3), and an Adjust layer.
-   Thumb keys (base): Left Alt, Left GUI, Space • Right: MO(\_SYM), MO(\_NUM), MO(\_FUNC).

Key behaviors used:

-   CTL_T(KC_ESC): Tap = Escape, Hold = Left Control.
-   LT(layer, key): Tap sends the key, hold activates the layer (Space acts as NAV when held).
-   MO(layer): Hold to access the layer; release to return.
-   QK_BOOT: Enter bootloader (for flashing firmware).

---

## Layers

### 0 — QWERTY (Base)

-   Standard QWERTY alphas.
-   Left home-row A key is CTL_T(KC_ESC) for tap Esc / hold Ctrl.
-   Right side punctuation; Backspace top-right; Enter bottom-right.
-   Thumbs: LAlt, LGUI, Space (LT(\_NAV, KC_SPC)) • Right: MO(\_SYM), MO(\_NUM), MO(\_FUNC).

### NAV — Navigation (via LT on Space)

-   Arrow keys on both halves (Left/Down/Up/Right) for quick navigation.

### 1 — Symbols (MO(\_SYM))

-   Symbols row: ~ ! @ # $ % ^ & \* ( )
-   Brackets/punctuation: - = ` [ ] \
-   Right thumb includes MO(\_ADJUST).

### 2 — Numbers & Function Keys (MO(\_NUM))

-   Numbers 1–0.
-   Function keys F1–F12 on the right half.
-   Right thumb includes MO(\_ADJUST).

### 3 — Function / Media / Mouse (MO(\_FUNC))

-   Brightness ±, Media keys (Prev/Play/Pause/Next, Mute, Vol±).
-   Mouse wheel and cursor controls (requires MOUSEKEY_ENABLE).

### Adjust (MO(\_ADJUST))

-   QK_BOOT for bootloader access.
-   Remaining keys reserved for future customization.

---

## Combos (enabled on QWERTY only)

Characters produced when pressing the pair simultaneously:

-   R + T → ( (KC_LPRN)
-   Y + U → ) (KC_RPRN)
-   F + G → [ (KC_LBRC)
-   H + J → ] (KC_RBRC)
-   V + B → { (KC_LCBR)
-   N + M → } (KC_RCBR)

Notes:

-   These combos trigger only when the QWERTY layer is active (enforced via `combo_should_trigger` in keymap.c).
-   If you want to adjust the timing window, use the commented line in `config.h`:
    -   `// #define COMBO_TERM 200` (uncomment to customize)

### Quick table

| Chord | Output |
| ----: | :----- |
| R + T | (      |
| Y + U | )      |
| F + G | [      |
| H + J | ]      |
| V + B | {      |
| N + M | }      |

Tips:

-   If rapid chords with close keys are hard to trigger, try increasing `COMBO_TERM` (e.g., 180–230 ms).
-   For overlapping chords (combos sharing keys), the longer chord takes precedence; simplify your chord set if necessary.

---

## Mod-Tap: tap Esc / hold Ctrl

For a stable Mod-Tap experience, the following are enabled in `config.h`:

-   `#define TAPPING_TERM 200`
-   `#define HOLD_ON_OTHER_KEY_PRESS`
-   `#define TAPPING_FORCE_HOLD`

---

## Build options (rules.mk)

-   MOUSEKEY_ENABLE = yes
-   EXTRAKEY_ENABLE = yes
-   COMBO_ENABLE = yes

---

## Build and flash

Target: crkbd/rev1 • Keymap: ergenekonyigit

### Build

```fish
qmk compile -kb crkbd/rev1 -km ergenekonyigit
```

### Flash

```fish
qmk flash -kb crkbd/rev1 -km ergenekonyigit
```

For split boards, flash each half according to your MCU/bootloader procedure (e.g., Pro Micro/Elite-C/Nice!Nano).

---

## Quick reference

-   Base: QWERTY; A = tap Esc / hold Ctrl.
-   NAV: while holding Space.
-   1: Symbols • 2: Numbers/F-keys • 3: Function/Media/Mouse • Adjust: Bootloader (QK_BOOT).

Feel free to customize by editing `keymap.c`, `config.h`, and `rules.mk` in this folder.
