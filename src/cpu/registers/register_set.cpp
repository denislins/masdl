#include "register_set.h"

using namespace masdl::cpu::registers;

RegisterSet::RegisterSet() {
  init_byte_registers();
  init_composite_registers();
  init_word_registers();
}

void RegisterSet::reset() {
  a_register_->reset();
  b_register_->reset();
  c_register_->reset();
  d_register_->reset();
  e_register_->reset();
  f_register_->reset();
  h_register_->reset();
  l_register_->reset();

  pc_register_->reset();
  sp_register_->reset();
  r_register_->reset();
}

void RegisterSet::init_byte_registers() {
  a_register_ = new ByteRegister();
  b_register_ = new ByteRegister();
  c_register_ = new ByteRegister();
  d_register_ = new ByteRegister();
  e_register_ = new ByteRegister();
  f_register_ = new FlagsRegister();
  h_register_ = new ByteRegister();
  l_register_ = new ByteRegister();
}

void RegisterSet::init_composite_registers() {
  af_register_ = new CompositeRegister(a_register_, f_register_);
  bc_register_ = new CompositeRegister(b_register_, c_register_);
  de_register_ = new CompositeRegister(d_register_, e_register_);
  hl_register_ = new CompositeRegister(h_register_, l_register_);
}

void RegisterSet::init_word_registers() {
  pc_register_ = new WordRegister();
  sp_register_ = new WordRegister(0xDFF0);
  r_register_ = new WordRegister();
}
