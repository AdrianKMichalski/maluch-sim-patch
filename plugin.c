#include "plugin.h"
#include "memutils.h"
#include "patches.h"

void patch_functions(void) {
  patch_call_instruction(0x40274E, get_engine_pitch);
}

void plugin_init(void) {
  patch_functions();
}
