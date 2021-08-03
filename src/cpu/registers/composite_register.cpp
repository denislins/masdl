#include "composite_register.h"

using namespace masdl::cpu::registers;

CompositeRegister::CompositeRegister(ByteRegister *register_a, ByteRegister *register_b) {
  register_a_ = register_a;
  register_b_ = register_b;
}

unsigned short CompositeRegister::read() {
  const unsigned char value_a = register_a_->read();
  const unsigned char value_b = register_b_->read();

  return (value_a << 8) | value_b;
}

void CompositeRegister::write(const unsigned short value) {
  register_a_->write(value >> 8);
  register_b_->write(value & 0xFF);
}
