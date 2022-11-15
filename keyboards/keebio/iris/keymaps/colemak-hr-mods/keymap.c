#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _NUMS 1
#define _NAV 2
#define _QWERTY 3

// Left-hand home row mods
#define HM_A LGUI_T(KC_A)
#define HM_R LALT_T(KC_R)
#define HM_S LSFT_T(KC_S)
#define HM_T LCTL_T(KC_T)
#define HM_SPC LT(_NUMS, KC_SPC)

// Right-hand home row mods
#define HM_N RCTL_T(KC_N)
#define HM_E RSFT_T(KC_E)
#define HM_I LALT_T(KC_I)
#define HM_O RGUI_T(KC_O)
#define HM_ENT LT(_NAV, KC_ENT)
#define HM_TAB LT(_NAV, KC_TAB)

#define TOG_GAME TG(_QWERTY)

enum {
	_ = SAFE_RANGE,
	LPRN,
	LBRC,
	LCBR,
};

// Tap dance indices
enum {
    // Home OS
    H_LOS = 0,
    // Home Enter
    H_RAL,
    // Toggle game layer on double tap, rshift when held
    GAME,
	// Usually shift, double tap to reset
    RST,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [H_LOS] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LGUI, _NUMS),
  [H_RAL] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RALT, _NAV),
  [GAME] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RSFT, _QWERTY),
  [RST] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, RESET),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,     KC_Y,   KC_SCLN, KC_BSLS,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_BSPC, HM_A,    HM_R,    HM_S,    HM_T,    KC_D,                               KC_H,    HM_N,    HM_E,     HM_I,   HM_O,    KC_QUOT,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         CAPSWRD, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,           KC_BSLS, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(GAME),
      //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        KC_LEFT, KC_DOWN,  HM_SPC,                   HM_ENT,  KC_UP,   KC_RGHT
      //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),

[_NUMS] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_PLUS, KC_7,    KC_8,    KC_9,    KC_COLN, KC_PIPE,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_ESC,  KC_EQL,  LBRC,    LCBR,    LPRN,    KC_UNDS,                            KC_DOT,  KC_4,    KC_5,    KC_6,    KC_MINS, KC_AMPR,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       TD(RST), KC_CIRC, KC_RBRC, KC_RCBR, KC_RPRN, KC_SLSH, _______,          _______, KC_COMM, KC_1,    KC_2,    KC_3,    KC_PLUS, KC_ASTR,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, _______,                   _______, KC_0,    KC_0
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),

[_NAV] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F4,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_MUTE, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,                            KC_BTN3, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_ACL2,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_ESC,  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_APP,                             KC_BTN2, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ACL1,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       TD(RST), RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,          _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL0,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, _______,                   _______, _______, _______
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),

[_QWERTY] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,           KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TOG_GAME,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, KC_SPC,                    KC_SPC,  _______, _______
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(H_LOS):
        case TD(H_RAL):
	    case TD(GAME):
	    case TD(RST):
            return TAPPING_TERM + 90;
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
	  // Please don't auto shift my tab ever
	  case KC_TAB:
		return false;
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
	    return true;
    }
    return get_custom_auto_shifted_key(keycode, record);
}
