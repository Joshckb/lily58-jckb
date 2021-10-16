#pragma once

#include <stdbool.h>
#include "quantum.h"

typedef enum {
  ENC_MODE_VOLUME = 0,
  ENC_MODE_LEFT_RIGHT,
  ENC_MODE_DOWN_UP,
  ENC_MODE_PAGING
} encoder_mode_t;

encoder_mode_t encoder_primary_mode;

void encoder_utils_init(void);

void set_encoder_mode(encoder_mode_t mode);

encoder_mode_t get_encoder_mode(void);

void encoder_action_volume(uint8_t clockwise);

void encoder_action_left_right(uint8_t clockwise);

void encoder_action_up_down(uint8_t clockwise);

void encoder_action_paging(uint8_t clockwise);

void encoder_action(encoder_mode_t mode, uint8_t clockwise);

