#include "lets_split.h"
#include "action_layer.h"

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
	KC_ESC,         KC_Q,     KC_W,     KC_E,     KC_R,        KC_T,    KC_Y,    KC_U,        KC_I,     KC_O,     KC_P,     KC_BSPC, \
	CTL_T(KC_TAB),  KC_A,     KC_S,     KC_D,     KC_F,        KC_G,    KC_H,    KC_J,        KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
	KC_LSFT,        KC_Z,     KC_X,     KC_C,     KC_V,        KC_B,    KC_N,    KC_M,        KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, \
	KC_LCTL,        KC_LALT,  KC_LGUI,  KC_LGUI,  MO(_LOWER),  KC_SPC,  KC_SPC,  MO(_RAISE),  KC_RGUI,  KC_RALT,  KC_RCTL,  KC_ENT
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
	_______,  _______,  _______,  _______,  _______,  _______,  _______,  MO(_ADJUST),   _______,  _______,  _______,  _______
),

/* Raise
 * ,-----------------------------------------. ,-----------------------------------------.
 * | ____ |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  | ____ |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | ____ |Shift | Ctrl |  Alt |  GUI | Entr | | Left | Down |  Up  |Right | Del  | ____ |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | ____ | ____ | ____ | Vol- | Prev | Play | | Mute | Next | Vol+ | ____ | ____ | ____ |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |Light | Ptrn | ____ | ____ | ____ | ____ | | ____ | XXXX | ____ | ____ | ____ | ____ |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_RAISE] = KEYMAP( \
	_______,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______, \
	_______,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,   KC_ENT,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_DEL,   _______, \
	_______,  _______,  _______,  KC_VOLD,  KC_MPRV,   KC_MPLY,  KC_MUTE,  KC_MNXT,  KC_VOLU,  _______,  _______,  _______, \
	RGB_TOG,  RGB_MOD,  _______,  _______,  MO(_ADJUST),   _______,  _______,  _______,  _______,  _______,  _______,  _______
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------. ,-----------------------------------------.
 * | ACL2 |  F1  |  F2  |  F3  |  F4  |      | |      | SclD | SclU |      |      |RESET |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | ACL1 |  Ms4 |  Ms3 |  Ms2 |  Ms1 |      | |  MsL |  MsD |  MsU |  MsR |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | ACL0 |  F9  |  F10 |  F11 |  F12 |      | |      |rgbh+ |rgbs+ |rgbv+ |      | AuOn |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |rgbh- |rgbs- |rgbv- |      | AuOf |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ADJUST] = KEYMAP( \
	KC_ACL2,  KC_FN1,   KC_FN2,   KC_FN3,   KC_FN4,   XXXXXXX,  XXXXXXX,  KC_WH_D,  KC_WH_U,  XXXXXXX,  XXXXXXX,  RESET,   \
	KC_ACL1,  KC_BTN4,  KC_BTN3,  KC_BTN2,  KC_BTN1,  XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  XXXXXXX,  XXXXXXX, \
	KC_ACL0,  KC_FN9,   KC_FN10,  KC_FN11,  KC_FN12,  XXXXXXX,  XXXXXXX,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  AU_ON,   \
	XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_HUD,  RGB_SAD,  RGB_VAD,  XXXXXXX,  AU_OFF
)

};
