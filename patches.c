#include "patches.h"

int32_t __thiscall get_engine_pitch(void *self, uint32_t player_or_opponent,
                                    uint32_t engine_speed) {
  uint32_t(__thiscall * original_function)(void *, uint32_t, uint32_t) =
      (void *)0x406F10;
  // Make the engine pitch higher on low RPM, but lower on high RPM range
  return original_function(self, player_or_opponent, engine_speed / 4 + 6000);
}
