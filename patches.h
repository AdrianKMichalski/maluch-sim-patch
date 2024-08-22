#pragma once

#include <stdint.h>

typedef float *floatptr_t;

typedef enum texture_id_t {
  TEXTURE_TARCZA_TGA = 0x0,
  TEXTURE_STRZALKA_TGA = 0x1,
  TEXTURE_MIGACZ_TGA = 0x2,
  TEXTURE_MIRROR_TGA = 0xC
} texture_id_t;

int32_t __thiscall get_engine_pitch(void *self, uint32_t player_or_opponent,
                                    uint32_t engine_speed);

int32_t __thiscall draw_hud_image(void *self, texture_id_t texture_id,
                                  float position_x, float position_y,
                                  float scale_x, float scale_y, float angle);

floatptr_t __stdcall create_projection_matrix(floatptr_t matrix,
                                              float fov_radians,
                                              float aspect_ratio, float near,
                                              float far);