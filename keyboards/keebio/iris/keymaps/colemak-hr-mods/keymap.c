#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _NUMS 1
#define _NAV 2
#define _QWERTY 3

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)
#define HOME_TAB LT(_NUMS, KC_TAB)
#define HOME_BSPC LT(_NUMS, KC_BSPC)

// Right-hand home row mods
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)
#define HOME_SPC LT(_NAV, KC_SPC)

#define TOG_GAME TG(_QWERTY)

// Tap dance indices
enum {
    // Home Tab
    H_TAB = 0,
    // Home Enter
    H_ENT,
    // Toggle game layer on double tap, rshift when held
    GAME,
    PRN,
    CBRK,
    BRC,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [H_TAB] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_TAB, _NUMS),
  [H_ENT] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_ENT, _NAV),
  [GAME] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RSFT, _QWERTY),
  [PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [CBRK] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  [BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LOCK,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,     KC_Y,   KC_SCLN, KC_BSLS,
      //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LCTL, HOME_A,   HOME_R,  HOME_S,  HOME_T, KC_D,                               KC_H,    HOME_N,  HOME_E,   HOME_I, HOME_O,  KC_QUOT,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   HOME_BSPC,         HOME_SPC, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,TD(GAME),
      //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        KC_LGUI,TD(H_TAB),HOME_BSPC,                 HOME_SPC,TD(H_ENT),KC_RALT
      //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),

[_NUMS] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_QUES, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PPLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_BSPC, KC_EQL,  TD(BRC), TD(CBRK),TD(PRN), KC_COLN,                            KC_UNDS, KC_4,    KC_5,    KC_6,    KC_MINS, KC_COLN,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       RESET,   KC_CIRC, KC_RBRC, KC_RCBR, KC_RPRN, KC_PIPE, _______,          _______, KC_ASTR,  KC_1,    KC_2,    KC_3,    KC_PLUS, KC_AMPR,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, _______,                    _______,_______, KC_0
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),

[_NAV] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F4,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_LOCK,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       RGB_TOG, BL_STEP, KC_VOLU, KC_VOLD, KC_MUTE, _______,                            KC_PSCR, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_ACL2,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       RGB_MOD, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_APP,                             KC_BTN2,  KC_LEFT, KC_UP,  KC_DOWN, KC_RGHT, KC_ACL1,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       RESET,   KC_PSCR, KC_MPRV, KC_MNXT, KC_MPLY, _______, _______,          _______, KC_BTN1, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, KC_ACL0,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, _______,                   _______, _______, _______
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),

[_QWERTY] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_CAPS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_SPC,           _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,TOG_GAME,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      _______, _______, KC_SPC,                    _______, _______, _______
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_BSPC:
        case HOME_SPC:
            return TAPPING_TERM + 90;
        default:
            return TAPPING_TERM;
    }
}
