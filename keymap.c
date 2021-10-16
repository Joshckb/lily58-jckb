#include QMK_KEYBOARD_H
#include "joshckb/joshckb.h"

#ifdef OLED_DRIVER_ENABLE
#include "oled.c"
#endif

#ifdef ENCODER_ENABLE
#include "encoder_utils.h"

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (layer_state_is(_RAISE)) {
      set_encoder_mode(ENC_MODE_LEFT_RIGHT);
  } else if (layer_state_is(_LOWER)) {
      set_encoder_mode(ENC_MODE_DOWN_UP);
  } else if (layer_state_is(_ADJUST)) {
      set_encoder_mode(ENC_MODE_PAGING);
  } else {
      set_encoder_mode(ENC_MODE_VOLUME);
  }

  encoder_action(get_encoder_mode(), clockwise);

  return true;
}
#endif

enum {
    TD_MENU_ADJS,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MENU_ADJS] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_APP, _AD),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QW] = LAYOUT( \
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_GRV,  \
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_MINS, \
    KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT, \
    KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_ENT,  KC_BSPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                    TD(TD_MENU_ADJS), KC_LALT, MO(_LW), KC_SPC,  KC_ENT,   MO(_RS), KC_LGUI, KC_CAPS \
  ),

  [_LW] = LAYOUT( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_EQL,  KC_MINS, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, \
    KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_BSLS, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, \
    KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, KC_DEL,  XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
  ),

  [_RS] = LAYOUT( \
    KC_TRNS, XXXXXXX, XXXXXXX, KC_MSTP, KC_MUTE, KC_VOLU,                   KC_PGUP, KC_P7,   KC_P8,  KC_P9,   KC_PAST, KC_PSLS, \
    KC_TRNS, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD,                   KC_PGDN, KC_P4,   KC_P5,  KC_P6,   KC_PPLS, KC_PMNS, \
    KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,                   KC_HOME, KC_P1,   KC_P2,  KC_P3,   XXXXXXX, KC_PEQL, \
    KC_TRNS, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX, KC_TRNS, KC_TRNS, KC_END,  KC_PCMM, KC_P0,  KC_PDOT, XXXXXXX, XXXXXXX, \
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
  ),

  [_AD] = LAYOUT( \
    KC_PWR,  KC_SLEP, KC_WAKE, XXXXXXX, XXXXXXX, KC_BRIU,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GUI_OFF, \
    KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GUI_ON,  \
    KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
  ),
};

