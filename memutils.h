#pragma once

#include <stdint.h>

typedef uint32_t address_t;
typedef address_t address_diff_t;

void patch_call_instruction(address_t instruction_address,
                            void *patch_function);
