#include "flags_register.h"

using namespace masdl::cpu::registers;

void FlagsRegister::update_sign_flag(const bool value) {
  update_flag(1 << 7, value);
}

void FlagsRegister::update_zero_flag(const bool value) {
  update_flag(1 << 6, value);
}

void FlagsRegister::update_half_carry_flag(const bool value) {
  update_flag(1 << 4, value);
}

void FlagsRegister::update_parity_flag(const bool value) {
  update_flag(1 << 2, value);
}

void FlagsRegister::update_subtract_flag(const bool value) {
  update_flag(1 << 1, value);
}

void FlagsRegister::update_carry_flag(const bool value) {
  update_flag(1, value);
}

void FlagsRegister::update_flag(const char mask, const bool value) {
  unsigned char updated_register_value = read();

  if (value) {
    updated_register_value |= mask;
  } else {
    updated_register_value &= ~mask;
  }

  write(updated_register_value);
}
