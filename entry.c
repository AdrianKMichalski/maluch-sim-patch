#define WIN32_LEAN_AND_MEAN
#include "plugin.h"
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved) {
  if (reason == DLL_PROCESS_ATTACH) {
    plugin_init();
  }
  return TRUE;
}
