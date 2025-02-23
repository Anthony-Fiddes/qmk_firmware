#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// TODO: Add underglow support to show current layer or at least caps lock!

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _NUMS 1
#define _NAV 2
#define _QWERTY 3

enum {
	_ = SAFE_RANGE,
	LPRN,
	LBRC,
	LCBR,
};

enum {
    // Toggle game layer on double tap, f9 when held
    GAME = 0,
    // Layer Toggles
    NAVT,
    NUMT,
	// Usually shift but caps on double tap
	SH_CA,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [GAME] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_F9, _QWERTY),
  [NAVT] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RALT, _NAV),
  [NUMT] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_APP, _NUMS),
  [SH_CA] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

// Left-hand home row mods
#define HM_A LGUI_T(KC_A)
#define HM_R LALT_T(KC_R)
#define HM_S LSFT_T(KC_S)
#define HM_T LCTL_T(KC_T)
#define HM_LSPC LT(_NUMS, KC_SPC)
#define HM_MEN LT(_NAV, KC_APP)

// Right-hand home row mods
#define HM_N RCTL_T(KC_N)
#define HM_E RSFT_T(KC_E)
#define HM_I LALT_T(KC_I)
#define HM_O RGUI_T(KC_O)
#define HM_RSPC LT(_NAV, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_F1,      KC_F2,   KC_GESC,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,    KC_PGUP, \
    KC_F3,      KC_F4,   KC_TAB,   KC_Q,    KC_W,    KC_F,     KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_LBRC, KC_RBRC, KC_BSLS,             KC_PGDN, \
    KC_F5,      KC_F6,   KC_BSPC,  HM_A,    HM_R,    HM_S,     HM_T,    KC_D,    KC_H,    HM_N,    HM_E,    HM_I,    HM_O,       KC_QUOT, KC_ENT,                       KC_HOME, \
    KC_F7,      KC_F8,   TD(SH_CA),KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT, KC_UP,                        KC_END, \
    TD(GAME),   KC_PSCR, KC_LCTL,  KC_LALT, KC_LGUI, TD(NUMT), HM_LSPC,           _______,HM_RSPC, TD(NAVT),KC_RCTL, KC_RGUI,    KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_NUMS] = LAYOUT_65_with_macro(
    _______, _______, KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,  KC_F8,    KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, _______, \
    _______, _______, KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_PLUS, KC_7,   KC_8,     KC_9,     KC_COLN, KC_PIPE, _______, KC_PIPE, _______, \
    _______, _______, KC_ESC,  KC_EQL,  LBRC,    LCBR,    LPRN,    KC_UNDS,  KC_DOT,  KC_4,   KC_5,     KC_6,     KC_MINS, KC_AMPR, _______, _______, \
    _______, _______, _______, KC_CIRC, KC_RBRC, KC_RCBR, KC_RPRN, KC_SLSH,  KC_COMM, KC_1,   KC_2,     KC_3,     KC_QUES, KC_ASTR, _______, _______, \
    RESET,   _______, _______, _______, _______, _______, _______,           _______, KC_0,   _______,  _______,  _______, _______, _______, _______
  ),

  [_NAV] = LAYOUT_65_with_macro(
    _______, _______, KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, _______, \
    _______, _______, _______, KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT, KC_MPLY, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______, _______, _______, \
    _______, _______, KC_ESC,  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______, _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______, _______, _______, \
    _______, RGB_TOG, _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, _______, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, _______, _______, _______, \
    RESET,   RGB_MOD, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_QWERTY] = LAYOUT_65_with_macro(
    _______,   _______,   KC_GESC, KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_HOME, \
    _______,   _______,   KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_END, \
    _______,   _______,   KC_BSPC, KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGUP, \
    _______,   _______,   KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,                     KC_PGDN, \
    TD(GAME),  _______,   KC_LCTL, KC_APP, KC_LGUI, KC_LALT,   KC_SPC,           _______, KC_SPC,  KC_RALT, KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case TD(GAME):
	case TD(NAVT):
	case TD(NUMT):
	case TD(SH_CA):
	  return TAPPING_TERM + 50;
	default:
	  return TAPPING_TERM;
  }
}


bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
	case LPRN:
	case LBRC:
	case LCBR:
	  return true;
	default:
	  return false;
  }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch(keycode) {
	case LPRN:
	  add_weak_mods(MOD_BIT(KC_LSFT));
	  if (!shifted) {
		register_code16(KC_9);
	  } else {
		register_code16(KC_0);
	  }
	  break;
	case LBRC:
	  if (!shifted) {
		register_code16(KC_LBRC);
	  } else {
		register_code16(KC_RBRC);
	  }
	  break;
	case LCBR:
	  add_weak_mods(MOD_BIT(KC_LSFT));
	  if (!shifted) {
		register_code16(KC_LBRC);
	  } else {
		register_code16(KC_RBRC);
	  }
	  break;
	default:
	  if (shifted) {
		add_weak_mods(MOD_BIT(KC_LSFT));
	  }
	  // Must be fixed if using Retro Shift
	  register_code16(keycode);
  }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch(keycode) {
	case LPRN:
	  if (!shifted) {
		unregister_code16(KC_9);
	  }
	  unregister_code16(KC_0);
	  break;
	case LBRC:
	  if (!shifted) {
		unregister_code16(KC_LBRC);
	  }
	  unregister_code16(KC_RBRC);
	  break;
	case LCBR:
	  if (!shifted) {
		unregister_code16(KC_LBRC);
	  }
	  unregister_code16(KC_RBRC);
	  break;
	default:
	  // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
	  unregister_code16(keycode & 0xFF);
  }
}

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#    ifndef NO_AUTO_SHIFT_ALPHA
	  case KC_A ... KC_Z:
#    endif
#    ifndef NO_AUTO_SHIFT_NUMERIC
	  case KC_1 ... KC_0:
#    endif
#    ifndef NO_AUTO_SHIFT_SPECIAL
	  case KC_MINUS ... KC_SLASH:
	  case KC_NONUS_BACKSLASH:
#    endif
	  // Please don't auto shift my tab ever
	  case KC_TAB:
		return false;
    }
    return get_custom_auto_shifted_key(keycode, record);
}
