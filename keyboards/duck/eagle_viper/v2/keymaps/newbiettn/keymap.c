#include QMK_KEYBOARD_H

enum custom_keycodes {
  CLOSEMAIL = SAFE_RANGE,
  QMKURL,
  MACAPP
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CLOSEMAIL:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("Kind regards,\nNgoc Tran");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
    case MACAPP:
      if (record->event.pressed) {
                //SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LALT) SS_DOWN(X_LGUI));
		SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_DOWN(X_LCTRL));

		//return MACRO(D(LSFT), D(LALT), D(LGUI), END);
                //return MACRO( D(LALT), T(C), U(LALT), END  );
      } else {
                //SEND_STRING(SS_UP(X_LSFT)SS_UP(X_LALT)SS_UP(X_LGUI));
		//return MACRO(U(LSFT), U(LALT), U(LGUI), END);
                //return MACRO( D(LALT), T(V), U(LALT), END  );
		SEND_STRING(SS_UP(X_LGUI) SS_UP(X_LALT) SS_UP(X_LCTRL));
      }

      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* layer 0: qwerty */
  [0] = LAYOUT_eagle_splits( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,  \
    KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,           KC_SLSH, KC_RSFT, MO(1),   \
    MACAPP,  KC_LALT, KC_LGUI,                                              KC_SPC,           KC_SPC,           KC_RGUI, KC_RALT, MO(2)    \
  ),

  [1] = LAYOUT_eagle_splits( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, \
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,          _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_RIGHT,                  _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_DOWN, _______, _______, \
    _______, _______, _______,                                              _______,          _______,          _______, _______, _______  \
  ),

  [2] = LAYOUT_eagle_splits( \
    RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, CLOSEMAIL, KC_SLEP, \
    _______, KC_BRID, KC_BRIU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _______, KC_MRWD, KC_MFFD, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, \
    _______, _______, _______,                                              _______,          _______,          _______, _______, _______  \
  ),

  [3] = LAYOUT_eagle_splits( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, \
    _______, _______, _______,                                              _______,          _______,          _______, _______, _______  \
  ),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE;
};
