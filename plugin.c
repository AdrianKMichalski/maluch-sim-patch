#include "plugin.h"
#include "memutils.h"
#include "patches.h"

static void patch_functions(void) {
  patch_call_instruction(0x40274E, get_engine_pitch);

  patch_call_instruction(0x404FAC, create_projection_matrix);

  address_t hud_calls[] = {0x40A246, 0x40A27F, 0x40A2A4, 0x40A2BD,
                           0x40A2EB, 0x40A3A4, 0x40C179};
  for (int i = 0; i < sizeof(hud_calls) / sizeof(*hud_calls); i++) {
    address_t address = hud_calls[i];
    patch_call_instruction(address, draw_hud_image);
  }
}

void plugin_init(void) { patch_functions(); }
