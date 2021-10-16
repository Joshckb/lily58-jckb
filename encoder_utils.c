#include "encoder_utils.h"

void encoder_utils_init(void) {
  encoder_primary_mode = ENC_MODE_VOLUME;
}

void set_encoder_mode(encoder_mode_t mode) {
  encoder_primary_mode = mode;
}

encoder_mode_t get_encoder_mode() {
  return encoder_primary_mode;
}

void encoder_action_volume(uint8_t clockwise) {
  if (clockwise) {
    tap_code(KC_VOLU);
  } else {
    tap_code(KC_VOLD);
  }
}

void encoder_action_left_right(uint8_t clockwise) {
  if (clockwise) {
    tap_code(KC_RGHT);
  } else {
    tap_code(KC_LEFT);
  }
}

void encoder_action_up_down(uint8_t clockwise) {
  if (clockwise) {
    tap_code(KC_UP);
  } else {
    tap_code(KC_DOWN);
  }
}

void encoder_action_paging(uint8_t clockwise) {
  if (clockwise) {
    tap_code(KC_PGUP);
  } else {
    tap_code(KC_PGDN);
  }
}

void encoder_action(encoder_mode_t mode, uint8_t clockwise) {
  switch(mode) {
    case ENC_MODE_VOLUME:
      encoder_action_volume(clockwise);
      break;
    case ENC_MODE_LEFT_RIGHT:
      encoder_action_left_right(clockwise);
      break;
    case ENC_MODE_DOWN_UP:
      encoder_action_up_down(clockwise);
      break;
    case ENC_MODE_PAGING:
      encoder_action_paging(clockwise);
      break;
    default:
      encoder_action_volume(clockwise);
      break;
  }
}

