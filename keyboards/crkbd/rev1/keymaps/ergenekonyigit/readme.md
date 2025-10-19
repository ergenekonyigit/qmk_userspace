## Corne (crkbd rev1) — ergenekonyigit keymap

![keyboard](./keyboard.jpeg)

### Overview

-   Base layout: QWERTY with home-row Control on the left A position (tap Escape, hold Control).
-   Three momentary layers for navigation (1), symbols/media (2), and numbers/F-keys (3), plus an Adjust layer.
-   Thumb keys: Left Alt, Left GUI, Space on the base layer; right thumbs are momentary layer keys MO(\_FIRST), MO(\_SECOND), MO(\_THIRD).

Special key behaviors used in this keymap:

-   CTL_T(KC_ESC): Tap = Escape, Hold = Left Control.
-   MO(layer): Hold to access the layer; release to return.
-   QK_BOOT: Enter bootloader (for flashing firmware).

---

## Layers

### 0 — QWERTY (Base)

-   Standard QWERTY alpha keys.
-   Left home row A key is CTL_T(KC_ESC) for tap Esc / hold Ctrl.
-   Punctuation on the right; Backspace on the top-right; Enter on the bottom-right.
-   Thumbs: LAlt, LGUI, Space (left) • MO(1), MO(2), MO(3) (right).

### 1 — Navigation (MO(\_FIRST))

-   Arrow keys on both halves for convenience (Left/Down/Up/Right).
-   Quick nav/edit style with Tab, Backspace, and Enter remaining accessible.

### 2 — Symbols & Media (MO(\_SECOND))

-   Top row symbols: ~ ! @ # $ % | ^ & \* ( )
-   Brackets and punctuation: - = ` [ ] \
-   Media controls: Prev/Play-Stop/Next, Mute, Vol-, Vol+; Screen Brightness ±.
-   Right thumb includes MO(\_ADJUST) from this layer.

### 3 — Numbers & Function Keys (MO(\_THIRD))

-   Numbers 1–0 on the top rows.
-   Function keys F1–F12 on the right half.
-   Right thumb includes MO(\_ADJUST) from this layer.

### Adjust (MO(\_ADJUST))

-   QK_BOOT on the top-left to enter bootloader.
-   Other positions are unassigned placeholders (XXXXXXX) for future customization.

---

## Encoders (optional)

If ENCODER_MAP_ENABLE is enabled at build time, the map provides per-layer rotations:

-   CCW/CW: Volume Down/Up
-   CCW/CW: Media Prev/Next
-   CCW/CW: RGB Value Down/Up (e.g., RM_VALD/RM_VALU)
-   CCW/CW: Arrow Right/Left

These four encoder definitions repeat across layers 0–3.

---

## RGB Lighting

From `config.h` (active when RGBLIGHT_ENABLE is set in your keyboard/keymap build):

-   Enabled effects: Breathing, Rainbow Mood/Swirl, Snake, Knight, Christmas, Static Gradient, RGB Test, Alternating, Twinkle.
-   Value limit: 120; Steps — Hue: 10, Saturation: 17, Value: 17.

Note: The encoder mapping references RGB value up/down helpers; if RGB Matrix/Light isn’t compiled in, those actions will be no-ops.

---

## Build options

From `rules.mk`:

-   MOUSEKEY_ENABLE = no
-   EXTRAKEY_ENABLE = yes (enables media keys, etc.)

---

## Build and flash

Target: crkbd/rev1 • Keymap: ergenekonyigit

### Compile

```fish
qmk compile -kb crkbd/rev1 -km ergenekonyigit
```

Alternatively, using make:

```fish
make crkbd/rev1:ergenekonyigit
```

### Enter bootloader

-   Use the QK_BOOT key on the Adjust layer, or
-   Press your controller’s physical reset/boot pins/buttons as applicable.

### Flash

QMK will guide flashing after compile if you used `qmk compile` with `-e CONVERT_TO` or `qmk flash`. Example direct flash:

```fish
qmk flash -kb crkbd/rev1 -km ergenekonyigit
```

For split boards, flash each half as required by your MCU/bootloader (e.g., Pro Micro/Elite-C/Nice!Nano procedures).

---

## Quick reference

-   Base: QWERTY with tap Esc/hold Ctrl on the left home A key.
-   Layer 1: Navigation & arrows.
-   Layer 2: Symbols, brightness, media; MO(\_ADJUST) on the right thumb.
-   Layer 3: Numbers and F-keys; MO(\_ADJUST) on the right thumb.
-   Adjust: Bootloader access (QK_BOOT).

Customize freely by editing `keymap.c`, `config.h`, and `rules.mk` in this folder.
