#define WIN32_LEAN_AND_MEAN
#include "memutils.h"
#include <windows.h>

#define CALL_INSTRUCTION_LENGTH 5

static void make_memory_writeable(address_t address, size_t length) {
  DWORD previous_protection_flags;
  VirtualProtect((void *)address, length, PAGE_EXECUTE_READWRITE,
                 &previous_protection_flags);
}

void patch_call_instruction(address_t instruction_address,
                            void *patch_function) {
  address_t original_call_offset_address =
      instruction_address + 1; // Skip E8 opcode prefix

  make_memory_writeable(original_call_offset_address, sizeof(address_t));

  address_diff_t patch_procedure_offset =
      (address_t)patch_function -
      (instruction_address +
       CALL_INSTRUCTION_LENGTH); // Callee address is relative
  // to the beginning of the next instruction

  *(address_t *)original_call_offset_address = patch_procedure_offset;
}
