#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUM 3
#define _FUNC 4
#define _NAV 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUM,
  FUNC,
  NAV,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_NUM   MO(_NUM)
#define KC_FUNC  MO(_FUNC)
#define KC_NAV   MO(_NAV)
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_ENT)
#define KC_ALTKN ALT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CTLTB,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,     Z,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH,  RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   LGUI,   NUM,   ENT,      SPC, FUNC, ALTKN \
                              //`--------------------'  `--------------------'
  ),

  [_NUM] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCTL,   GRV,  LBRC,  LCBR,  LPRN,  SLSH,                   BSLS,  RPRN,  RCBR,  RBRC,  MINS,   EQL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  UNDS,  PLUS, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   LGUI,   NUM,   ENT,     BSPC,   NAV, ALTKN \
                              //`--------------------'  `--------------------'
  ),

  [_FUNC] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____,    1,     2,     3,     4,     5,                       6,     7,     8,     9,     0, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, LSFT,  LCTL,  LALT,  LGUI, _____,                    LEFT,  DOWN,    UP,  RGHT,   DEL, _____,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,_____, _____, _____, _____, _____,                    MPRV,  VOLD,  VOLU,  MNXT,  MUTE, _____,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   LGUI,   NAV,   ENT,      SPC, FUNC,  MPLY \
                              //`--------------------'  `--------------------'
  ),

  [_NAV] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        RST,  LRST, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,   PWR,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI,  LTOG, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LMOD,  LHUD,  LSAD,  LVAD, XXXXX, XXXXX,                  XXXXX,  BRID,  BRIU, XXXXX, XXXXX,  SLEP,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   LGUI,   NUM,   ENT,      SPC, FUNC, ALTKN \
                              //`--------------------'  `--------------------'
  )
};
