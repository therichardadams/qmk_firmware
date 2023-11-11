/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _QWERTY = 0,
    _COLEMAK,
    _SYM,
    _NAV,
    _ADJUST,
    _NUM
};

enum custom_keycodes {
    KC_PRVWD = SAFE_RANGE,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_DWRD,
    KC_NTAB,
    KC_PTAB,
    KC_BBCK,
    KC_BFWD,
    KC_OLDL,
    KC_OLDM,
    KC_OLDH,
    KC_UKHASH
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define ADJUST   MO(_ADJUST)
#define NUM      MO(_NUM)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOT)
#define SFT_GRV  MT(MOD_LSFT, KC_GRV)
#define SFT_TLD  MT(MOD_RSFT, KC_TILD)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |LShift/`|   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? |RShift/~|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute | LAlt | LGUI | Space| Sym  |  | Nav  | Enter|  Num | Hyper| Play |
 *                        |      |      |      |      |      |  |      |      |      |      | Pause|
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
     CTL_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, CTL_QUOT,
     SFT_GRV,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,   KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  SFT_TLD,
                                KC_MUTE, KC_LALT, KC_LGUI,  KC_SPC,     SYM,       NAV,  KC_ENT,    NUM, KC_HYPR, KC_MPLY
    ),

/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |      |      |  |      |      |   K  |   H  | ,  < | . >  | /  ? |RShift/~|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute | LAlt | LGUI | Space| Sym  |  | Nav  | Enter|  Num | Hyper| Play |
 *                        |      |      |      |      |      |  |      |      |      |      | Pause|
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK] = LAYOUT(
      KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
     CTL_ESC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, CTL_QUOT,
     SFT_GRV,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,   KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  SFT_TLD,
                                KC_MUTE, KC_LALT, KC_LGUI,  KC_SPC,     SYM,       NAV,  KC_ENT,    NUM, KC_HYPR, KC_MPLY
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______,KC_DLINE, KC_DWRD, XXXXXXX,  KC_APP,  KC_INS,                                     XXXXXXX, KC_PTAB,   KC_UP, KC_NTAB, XXXXXXX,  KC_DEL,
      _______,KC_LSTRT,KC_PRVWD,KC_NXTWD, KC_LEND, KC_CAPS,                                     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,  KC_DEL,
      _______, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, KC_PSCR, _______, _______, _______, _______, XXXXXXX, KC_BBCK, XXXXXXX, KC_BFWD, XXXXXXX, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      _______, KC_EXLM,   KC_AT,  KC_HASH,  KC_DLR, KC_PERC,                                     KC_DQUO,  KC_EQL, KC_LPRN, KC_RPRN,  KC_EQL, _______,
      _______, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,                                     KC_QUOT, KC_MINS, KC_LCBR, KC_RCBR, KC_PLUS, XXXXXXX,
      _______,  KC_GRV,KC_TILDE,KC_UKHASH, XXXXXXX, XXXXXXX, _______, _______, _______, _______, KC_PIPE, KC_UNDS, KC_LBRC, KC_RBRC, KC_BSLS, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      XXXXXXX, QK_BOOT,  QWERTY, COLEMAK, AG_TOGG, XXXXXXX,                                       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, XXXXXXX,
      XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
      XXXXXXX, XXXXXXX, KC_OLDL, KC_OLDM, KC_OLDH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15, XXXXXXX,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/* NUM
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |   4  |   5  |   6  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,------+------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |   0  |   1  |   2  |   3  |   .  |        |
 * `-------------------------------------------+------|------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
     */
    [_NUM] = LAYOUT(
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_0,    KC_1,    KC_2,    KC_3,  KC_DOT, XXXXXXX,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

#ifdef OLED_ENABLE

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED 10
#    define MIN_RUN_SPEED 40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
#    define ANIM_SIZE 96            // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                   }};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    void oled_write_split_anim(const char* data, int row) {
        const int ANIM_STRIDE = ANIM_SIZE / 3;
        for (int i = 0; i < 3; ++i) {
            oled_set_cursor(LUNA_X, row + i);
            oled_write_raw_P(data + i * ANIM_STRIDE, ANIM_STRIDE);
        }
    }

    /* animation */
    void animate_luna(void) {
        int row = LUNA_Y;
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);
            row = LUNA_Y - 1;
            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_split_anim(bark[current_frame], row);

        } else if (isSneaking) {
            oled_write_split_anim(sneak[current_frame], row);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_split_anim(sit[current_frame], row);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_split_anim(walk[current_frame], row);

        } else {
            oled_write_split_anim(run[current_frame], row);
        }
    }

#    if OLED_TIMEOUT > 0
    /* the animation prevents the normal timeout from occuring */
    if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return;
    } else {
        oled_on();
    }
#    endif

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }
}

/* KEYBOARD PET END */

void oled_write_split_os_mode(const char* data) {
    const int ANIM_STRIDE = 16;
    for (int i = 0; i < 2; ++i) {
        oled_set_cursor(0, i);
        oled_write_raw_P(data + i * ANIM_STRIDE, ANIM_STRIDE);
    }
}

void print_os_mode(void) {
//    // 'Apple', 16x16px
//    const char apple[] PROGMEM = {
//        0x00, 0xc0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xec, 0xee, 0xf7, 0xf1, 0xf0, 0x70, 0x20, 0x00,
//        0x00, 0x0f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0x7f, 0x3c, 0x18, 0x00
//    };
//    // 'Windows', 16x16px
//    const char windows[] PROGMEM = {
//        0x00, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xfe, 0x00, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
//        0x00, 0x3e, 0x3e, 0x3e, 0x3e, 0x7e, 0x7e, 0x00, 0x7e, 0x7e, 0x7e, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe
//    };
    if (keymap_config.swap_lalt_lgui) {
        oled_write_P(PSTR("Win"), false);
//        oled_write_split_os_mode(windows);
    } else {
        oled_write_P(PSTR("Mac"), false);
//        oled_write_split_os_mode(apple);
    }
}

void print_layout(void) {
    oled_set_cursor(7, 0);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwerty "), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("Colemak"), false);
            break;
        default:
            oled_write_P(PSTR("???????"), false);
    }
}

void print_layer(void) {
    oled_set_cursor(17, 0);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav "), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj "), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num "), false);
            break;
        default:
            oled_write_P(PSTR("??? "), false);
    }
}

void print_status(void) {
    print_os_mode();
    print_layout();
    print_layer();

    // Print mods
    uint8_t mods = get_mods();
    oled_set_cursor(0, 5);
    oled_write_P(mods & MOD_MASK_GUI ? PSTR("Cmd  ") : PSTR("     "), false);
    oled_set_cursor(0, 6);
    oled_write_P(mods & MOD_MASK_ALT ? PSTR("Opt  ") : PSTR("     "), false);
    oled_set_cursor(0, 7);
    oled_write_P(mods & MOD_MASK_CTRL ? PSTR("Ctrl ") : PSTR("     "), false);

    // Print locks
    led_t led_usb_state = host_keyboard_led_state();
    oled_set_cursor(16, 5);
    oled_write_P(led_usb_state.num_lock    ? PSTR("NUM ") : PSTR("    "), false);
    oled_set_cursor(16, 6);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    oled_set_cursor(16, 7);
    oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPS") : PSTR("    "), false);

    render_luna(8, 5);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status();
    } else {
        render_luna(0, 13);
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Scroll wheel
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    }
    return false;
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
//        case KC_QWERTY:
//            if (record->event.pressed) {
//                set_single_persistent_default_layer(_QWERTY);
//            }
//            return false;
//        case KC_COLEMAK:
//            if (record->event.pressed) {
//                set_single_persistent_default_layer(_COLEMAK);
//            }
//            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_mods(mod_config(MOD_LCTL));
                } else {
                    register_mods(mod_config(MOD_LALT));
                }
                register_code(KC_LEFT);
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                } else {
                    unregister_mods(mod_config(MOD_LALT));
                }
                unregister_code(KC_LEFT);
            }
            return false;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_mods(mod_config(MOD_LCTL));
                } else {
                    register_mods(mod_config(MOD_LALT));
                }
                register_code(KC_RIGHT);
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                } else {
                    unregister_mods(mod_config(MOD_LALT));
                }
                unregister_code(KC_RIGHT);
            }
            return false;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_code(KC_HOME);
                } else {
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_code(KC_HOME);
                } else {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_LEFT);
                }
            }
            return false;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_code(KC_END);
                } else {
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_code(KC_END);
                } else {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_RIGHT);
                }
            }
            return false;
        case KC_DLINE:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_mods(mod_config(MOD_LCTL));
                } else {
                    register_mods(mod_config(MOD_LGUI));
                }
                register_code(KC_BSPC);
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                } else {
                    unregister_mods(mod_config(MOD_LGUI));
                }
                unregister_code(KC_BSPC);
            }
            return false;
        case KC_DWRD:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LALT));
                unregister_code(KC_BSPC);
            }
            return false;
        case KC_NTAB:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_TAB);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_TAB);
            }
            return false;
        case KC_PTAB:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_mods(mod_config(MOD_LSFT));
                register_code(KC_TAB);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_mods(mod_config(MOD_LSFT));
                unregister_code(KC_TAB);
            }
            return false;
        case KC_BBCK:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_mods(mod_config(MOD_LGUI)); //left alt
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_LBRC);
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_mods(mod_config(MOD_LGUI)); //left alt
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_LBRC);
                }
            }
            return false;
        case KC_BFWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_mods(mod_config(MOD_LGUI)); //left alt
                    register_code(KC_RGHT);
                } else {
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_RBRC);
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_mods(mod_config(MOD_LGUI)); //left alt
                    unregister_code(KC_RGHT);
                } else {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_RBRC);
                }
            }
            return false;
        case KC_OLDH:
            if (record->event.pressed) {
                oled_set_brightness(0xFF);
            }
            return false;
        case KC_OLDM:
            if (record->event.pressed) {
                oled_set_brightness(0x8F);
            }
            return false;
        case KC_OLDL:
            if (record->event.pressed) {
                oled_set_brightness(0x0F);
            }
            return false;
        case KC_UKHASH:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    // TODO
                } else {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_3);
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    // TODO
                } else {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_3);
                }
            }
            return false;

        /* KEYBOARD PET STATUS START */

        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;

        /* KEYBOARD PET STATUS END */
    }
    return true;
}
