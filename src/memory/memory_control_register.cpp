#include "memory_control_register.h"

using namespace masdl::memory;

void MemoryControlRegister::write(const unsigned char value) {
  if ((value & 8) > 0) {
    ram_banking_enabled_ = true;

    if ((value & 4) > 0) {
      current_ram_bank_ = 1;
    } else {
      current_ram_bank_ = 0;
    }
  } else {
    ram_banking_enabled_ = false;
  }
}

bool MemoryControlRegister::is_ram_banking_enabled() {
  return ram_banking_enabled_;
};

unsigned char MemoryControlRegister::get_current_ram_bank() {
  return current_ram_bank_;
};
