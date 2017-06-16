#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom macros
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift
#define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
#define MEH_GRV     MEH_T(KC_GRV)               // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  | |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |Ctl/Tab|  A  |   S  |   D  |   F  |   G  | |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |  Alt | GUI  | GUI  |Lower |Space | |Space |Raise |  GUI |  Alt | Ctl  |Enter |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = KEYMAP( \
	KC_ESC,         KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,     KC_P,     KC_BSPC, \
	CTL_T(KC_TAB),  KC_A,     KC_S,     KC_D,     KC_F,   KC_G,    KC_H,    KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
	KC_LSFT,        KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, \
	KC_LCTL,        KC_LALT,  KC_LGUI,  KC_LGUI,  LOWER,  KC_SPC,  KC_SPC,  RAISE,  KC_RGUI,  KC_RALT,  KC_RCTL,  KC_ENT
),

/* Lower
 * ,-----------------------------------------. ,-----------------------------------------.
 * |  ___ |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | ____ |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |   `  |  [   |  {   |  (   |  /   | |  \   |   )  |   }  |   ]  |   -  |  =   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | ____ |   !  |  @   |  #   |  $   |  %   | |  ^   |  &   |  *   |   _  |   +  | ____ |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | ____ | ___  | ___  | ___  | XXXX |      | |      | ____ | ____ | ____ |  __  | ____ |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_LOWER] = KEYMAP( \
	_______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,      KC_8,     KC_9,     KC_0,     _______, \
	KC_LCTL,  KC_GRV,   KC_LBRC,  KC_LCBR,  KC_LPRN,  KC_SLSH,  KC_BSLS,  KC_RPRN,   KC_RCBR,  KC_RBRC,  KC_MINS,  KC_EQL,  \
	_______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,   KC_ASTR,  KC_UNDS,  KC_PLUS,  _______, \
	_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______
),

/* Raise
 * ,-----------------------------------------. ,-----------------------------------------.
 * | ____ |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | ____ |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | ____ |Shift | Ctrl |  Alt |  GUI | ____ | | Left | Down |  Up  |Right | Del  | ____ |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | ____ |Light | ____ | Vol- | Prev | Play | | Mute | Next | Vol+ | ____ | ____ | ____ |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | ____ | ____ | ____ | ____ | ____ | ____ | | ____ | XXXX | ____ | ____ | ____ | ____ |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_RAISE] = KEYMAP( \
	_______,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______, \
	_______,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,   _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_DEL,   _______, \
	_______,  _______,  _______,  KC_VOLD,  KC_MPRV,   KC_MPLY,  KC_MUTE,  KC_MNXT,  KC_VOLU,  _______,  _______,  _______, \
	_______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______
),


/* Adjust (Lower + Raise)
 */
[_ADJUST] = KEYMAP( \
	KC_MS_ACCEL2,  KC_FN1,      KC_FN2,      KC_FN3,      KC_FN4,      XXXXXXX,  XXXXXXX,     KC_WH_D,     KC_WH_U,   XXXXXXX,      XXXXXXX,  RESET,   \
	KC_MS_ACCEL1,  KC_MS_BTN4,  KC_MS_BTN3,  KC_MS_BTN2,  KC_MS_BTN1,  XXXXXXX,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_UP,  KC_MS_RIGHT,  XXXXXXX,  XXXXXXX, \
	KC_MS_ACCEL0,  KC_FN9,      KC_FN10,     KC_FN11,     KC_FN12,     XXXXXXX,  XXXXXXX,     XXXXXXX,     XXXXXXX,   XXXXXXX,      XXXXXXX,  AU_ON,   \
	XXXXXXX,       XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,  XXXXXXX,     XXXXXXX,     XXXXXXX,   XXXXXXX,      XXXXXXX,  AU_OFF
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
