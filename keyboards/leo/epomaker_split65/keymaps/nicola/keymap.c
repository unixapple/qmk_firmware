// Copyright 2025 EPOMAKER (@Epomaker)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "rgb_record/rgb_record.h"

#include "nicola.h" // NICOLA親指シフト
#include "jtu.h"    // JIS keyboard on ANSI layout hardware

// Japanese IME keys
#define KC_HENK   0x8A  // Henkan
#define KC_MHEN   0x8B  // Muhenkan
#define KC_LANG1  0x90  // Katakana/Hiragana (Japanese mode)
#define KC_LANG2  0x91  // Eisu (Alphanumeric mode)

#define RGBLED_NUM 0
#define X_MHEN   KC_MHEN
#define X_LANG2  KC_LANG2
#define X_HENK   KC_HENK
#define X_LANG1  KC_LANG1

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

//enum layers {
//    _BL = 0,
//    _FL,
//    _MBL,
//    _MFL,
//};

#define ______ HS_BLACK

enum keymap_layers {
  _QWERTY,
// NICOLA親指シフト
  _NICOLA, // NICOLA親指シフト入力レイヤー
// NICOLA親指シフト
  _FUNC,
  _FL //FL layer of split65 original
};

enum custom_keycodes {
  KC_EISU = NG_SAFE_RANGE,
  KC_KANA2
};

 //オリジナルの"LAYOUT_62_ansi_2space"がなかったため"LAYOUT"へ変更
 //"LAYOUT"は引数69に対して、ansiが引数65で足りなかったため、ダミーで4つ追加した→後で調整
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,           KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,   KC_MUTE, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,  KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_INT1, \
      MO(_FUNC), KC_A,  KC_S,    KC_D,    KC_F,    KC_G,              KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENT, KC_PGUP, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_UP,   KC_PGDN,  \
      KC_LCTL, KC_LCMD , KC_LALT,             KC_SPC,        KC_SPC, KC_DEL, MO(_FL), KC_RCTL, KC_LEFT,  KC_DOWN, KC_RIGHT ), 

// NICOLA親指シフト
  // デフォルトレイヤーに関係なくQWERTYで
    [_NICOLA] = LAYOUT( \
      KC_ESC,  NG_1,    NG_2,    NG_3,    NG_4,    NG_5,    NG_6,           NG_7,   NG_8,    NG_9,    NG_0,    NG_MINS,  NG_EQL,  KC_BSPC,   KC_MUTE, \
      KC_TAB,  NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,                 NG_Y,    NG_U,   NG_I,    NG_O,    NG_P,  NG_LBRC,  NG_RBRC,  NG_BSLS,  KC_INT1, \
      MO(_FUNC), NG_A,  NG_S,    NG_D,    NG_F,    NG_G,              NG_H,    NG_J,   NG_K,    NG_L,    NG_SCLN, NG_QUOT,  KC_ENT, KC_PGUP,  \
      KC_LSFT, NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,           NG_N,    NG_M,   NG_COMM, NG_DOT,  NG_SLSH, KC_RSFT,  KC_UP,  KC_PGDN,   \
      KC_LCTL, KC_LCMD,  KC_LALT,             NG_SHFTL,     NG_SHFTR, KC_DEL, MO(_FL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT ),

  // Function Layer, KC_BSLS is not confirmed
  [_FUNC] = LAYOUT( \
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,    KC_MUTE, \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG,              LCTL(KC_LEFT), KC_PGDN, KC_PGUP, LCTL(KC_RIGHT), KC_PSCR, KC_TRNS, KC_BRK, KC_TRNS,  KC_TRNS, \
      MO(_FUNC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_INS,  KC_DEL,  KC_ENT, KC_PGUP,  \
      KC_LSFT, LCTL(LALT(KC_DEL)),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLSH, KC_RSFT, KC_UP,  KC_PGDN,   \
      KC_TRNS, KC_TRNS,    KC_TRNS,             KC_EISU,      KC_KANA2, KC_TRNS, MO(_FL), KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT ),

  // Function layer of split65
  [_FL] = LAYOUT( \
      KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,  KC_F12,   EE_CLR,   KC_TRNS, \
      RGB_MOD,  KC_BT1,   KC_BT2,   KC_BT3,   KC_2G4,   KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,  RGB_HUD, RGB_HUI,  KC_TRNS,  KC_INS,  \
      KC_TRNS,  KC_A,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,    RGB_SAD,  RGB_SAI, KC_TRNS,            KC_HOME, \
      KC_TRNS,  KC_TRNS,  RGB_TOG,  KC_TRNS,  KC_TRNS,  KC_TRNS,            NK_TOGG,  KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,           KC_TRNS,  RGB_VAI,  KC_END, \
      KC_FILP,  GU_TOGG,  KC_TRNS,  KC_BATQ,                                KC_BATQ,  KC_TRNS,  KC_TRNS, KC_TRNS,                       RGB_SPD,  RGB_VAD,  RGB_SPI)
 
};


// clang-format off
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// 
//     [_BL] = LAYOUT( /* Base */
//         KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_MUTE,
//         KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_DEL,   
//         KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,            KC_PGUP,
//         KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,   KC_PGDN,
//         KC_LCTL,  KC_LCMD,  KC_LALT,  KC_SPC,                                 KC_SPC,   KC_RALT,  MO(_FL),  KC_RCTL,                      KC_LEFT,  KC_DOWN, KC_RGHT),
// 
//     [_FL] = LAYOUT( /* Base */
//         KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,  KC_F12,   EE_CLR,   _______,
//         RGB_MOD,  KC_BT1,   KC_BT2,   KC_BT3,   KC_2G4,   _______,            _______,  _______,  _______, _______,    _______,  RGB_HUD, RGB_HUI,  _______,  KC_INS,  
//         _______,  KC_A,     TO(_MBL), _______,  _______,  _______,            _______,  _______,  _______, _______,    RGB_SAD,  RGB_SAI, _______,            KC_HOME, 
//         _______,  _______,  RGB_TOG,  _______,  _______,  _______,            NK_TOGG,  _______,  _______, _______,    _______,           _______,  RGB_VAI,  KC_END,
//         KC_FILP,  GU_TOGG,  _______,  KC_BATQ,                                KC_BATQ,  _______,  _______, _______,                       RGB_SPD,  RGB_VAD,  RGB_SPI),
// 
//     [_MBL] = LAYOUT( /* Base */
//         KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_MUTE,
//         KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_DEL,   
//         KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,            KC_PGUP,
//         KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,   KC_PGDN,
//         KC_LCTL,  KC_LALT,  KC_LGUI,  KC_SPC,                                 KC_SPC,   KC_RGUI,  MO(_MFL), KC_RCTL,                      KC_LEFT,  KC_DOWN, KC_RGHT),
//     [_MFL] = LAYOUT( /* Base */
//         KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,  KC_F12,   EE_CLR,   _______,
//         RGB_MOD,  KC_BT1,   KC_BT2,   KC_BT3,   KC_2G4,   _______,            _______,  _______,  _______, _______,    _______,  RGB_HUD, RGB_HUI,  _______,  KC_INS,  
//         _______,  TO(_BL),  KC_S,     _______,  _______,  _______,            _______,  _______,  _______, _______,    RGB_SAD,  RGB_SAI, _______,            KC_HOME, 
//         _______,  _______,  RGB_TOG,  _______,  _______,  _______,            NK_TOGG,  _______,  _______, _______,    _______,           _______,  RGB_VAI,  KC_END,
//         KC_FILP,  _______,  _______,  KC_BATQ,                                KC_BATQ,  _______,  _______, _______,                       RGB_SPD,  RGB_VAD,  RGB_SPI),
// 
// };

// ここからnicola mechanismの移植領域

void matrix_init_user(void) {
  // NICOLA親指シフト
  set_nicola(_NICOLA);
  // NICOLA親指シフト
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case KC_EISU:
      if (record->event.pressed) {
        // NICOLA親指シフト
        //send_string(SS_TAP(X_MHEN));		// Win
        tap_code(X_MHEN);      // Win
        //send_string(SS_TAP(X_LANG2));		// Mac
        tap_code(X_LANG2);     // Mac
//        send_string(SS_LALT(SS_TAP(KC_LSHIFT())));	// ANSI⇔JIS
        nicola_off();
        // NICOLA親指シフト

/* LED関連はひとまずコメントアウト
//        RGBLIGHT_MODE_RAINBOW_SWIRL(0);
//        rgblight_sethsv_at(170,255,40, RGBLED_NUM-1); // the last LED = BLUE (NICOLA off)
        for(int i=0; i<RGBLED_NUM; ++i) {
            rgblight_setrgb_at(0, 0, 128, i);  // BLUE
        }
*/

      }
      return false;
      break;
    case KC_KANA2:
      if (record->event.pressed) {
        // NICOLA親指シフト
//        send_string(SS_LALT(SS_TAP(KC_LSHIFT())));	// ANSI⇔JIS
        //send_string(SS_TAP(X_HENK));		// Win
        tap_code(X_HENK);      // Win	
        //send_string(SS_TAP(X_LANG1));		// Mac
        tap_code(X_LANG1);     // Mac
        nicola_on();
        // NICOLA親指シフト

/* LED関連はひとまずコメントアウト
//        RGBLIGHT_MODE_RAINBOW_MOOD(0);
//        rgblight_sethsv_at(85,255,40, RGBLED_NUM-1); // the last LED = GREEN (NICOLA on)
        for(int i=0; i<RGBLED_NUM; ++i) {
            rgblight_setrgb_at(0, 126, 0, i);	// GREEN
        }
*/

      }
      return false;
      break;
  }

  // NICOLA親指シフト
  bool a = true;
  if (nicola_state()) {
    nicola_mode(keycode, record);
    a = process_nicola(keycode, record);
  }
  if (a == false) return false;
  // NICOLA親指シフト

//   bool continue_process = process_jtu(keycode, record);
//   if (continue_process == false) {
//     return false;
//   }

  return true;
}

// ここまでnicola mechanismの移植領域

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(_______, _______)},
    [2] = {ENCODER_CCW_CW(_______, _______)},
    [3] = {ENCODER_CCW_CW(_______, _______)},
};
#endif
// clang-format on

bool is_keyboard_master(void) {
    setPinInput(SPLIT_HAND_PIN);
    return readPin(SPLIT_HAND_PIN);
}

