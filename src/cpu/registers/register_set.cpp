#include "register_set.h"

using namespace masdl::cpu::registers;

RegisterSet::RegisterSet() {
  init_byte_registers();
  init_composite_registers();
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

void RegisterSet::init_composite_registers() {
  af_register_ = new CompositeRegister(a_register_, flags_register_);
  bc_register_ = new CompositeRegister(b_register_, c_register_);
  de_register_ = new CompositeRegister(d_register_, e_register_);
  hl_register_ = new CompositeRegister(h_register_, l_register_);
}
