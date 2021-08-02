#include "byte_register.h"

using namespace masdl::cpu::registers;

void ByteRegister::reset() {
  value_ = 0;
}

unsigned char ByteRegister::read() {
  return value_;
}

void ByteRegister::write(const unsigned char value) {
  value_ = value;
}
