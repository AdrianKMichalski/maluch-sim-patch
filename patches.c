#include "patches.h"

int32_t __thiscall get_engine_pitch(void *self, uint32_t player_or_opponent,
                                    uint32_t engine_speed) {
  uint32_t(__thiscall * original_function)(void *, uint32_t, uint32_t) =
      (void *)0x406F10;

  // Make the engine pitch higher on low RPM, but lower on high RPM range
  return original_function(self, player_or_opponent, engine_speed / 4 + 6000);
}

int32_t __thiscall draw_hud_image(void *self, texture_id_t texture_id,
                                  float position_x, float position_y,
                                  float scale_x, float scale_y, float angle) {
  float ratio = 1;
  // Do not shrink mirror
  if (texture_id != TEXTURE_MIRROR_TGA) {
    ratio = (16.0f / 9.0f) / (4.0f / 3.0f);
  }

  // Align speedometer position
  if (texture_id == TEXTURE_TARCZA_TGA || texture_id == TEXTURE_MIGACZ_TGA ||
      texture_id == TEXTURE_STRZALKA_TGA) {
    float texture_to_screen_width_ratio = 256.0f * 40.0f / 64000.0f;
    float width_ratio_difference =
        texture_to_screen_width_ratio * (1 - 1 / ratio);

    if (texture_id == TEXTURE_STRZALKA_TGA) {
      // Align relative to the speedometer center
      position_x += width_ratio_difference / 2.0f;
    } else {
      position_x += width_ratio_difference;
    }
  }

  uint32_t(__thiscall * original_function)(void *, int32_t, float, float, float,
                                           float, float) = (void *)0x406AC0;

  return original_function(self, texture_id, position_x, position_y,
                           scale_x / ratio, scale_y, angle);
}

floatptr_t __stdcall create_projection_matrix(floatptr_t matrix,
                                              float fov_radians,
                                              float aspect_ratio, float near,
                                              float far) {
  floatptr_t(__stdcall * original_function)(floatptr_t, float, float, float,
                                            float) = (void *)0x419C71;

  return original_function(matrix, fov_radians, 16.0f / 9.0f, near, far);
}
