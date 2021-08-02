#include "register_set.h"

using namespace masdl::cpu::registers;

RegisterSet::RegisterSet() {
  init_byte_registers();
}

void RegisterSet::init_byte_registers() {
  a_register_ = new ByteRegister();
  b_register_ = new ByteRegister();
  c_register_ = new ByteRegister();
  d_register_ = new ByteRegister();
  e_register_ = new ByteRegister();
  h_register_ = new ByteRegister();
  l_register_ = new ByteRegister();

  flags_register_ = new FlagsRegister();
}

void RegisterSet::reset() {
  a_register_->reset();
  b_register_->reset();
  c_register_->reset();
  d_register_->reset();
  e_register_->reset();
  flags_register_->reset();
  h_register_->reset();
  l_register_->reset();
}
