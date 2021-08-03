#include "word_register.h"

using namespace masdl::cpu::registers;

WordRegister::WordRegister() {
  default_value_ = 0;
}

WordRegister::WordRegister(const unsigned short default_value) {
  default_value_ = default_value;
}

void WordRegister::reset() {
  value_ = default_value_;
}

unsigned short WordRegister::read() {
  return value_;
}

void WordRegister::write(const unsigned short value) {
  value_ = value;
}
