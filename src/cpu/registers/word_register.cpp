#include "word_register.h"

using namespace masdl::cpu::registers;

void WordRegister::reset() {
  value_ = 0;
}

unsigned short WordRegister::read() {
  return value_;
}

void WordRegister::write(const unsigned short value) {
  value_ = value;
}
