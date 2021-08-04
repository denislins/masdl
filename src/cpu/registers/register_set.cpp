#include "register_set.h"

using namespace masdl::cpu::registers;

RegisterSet::RegisterSet() {
  init_byte_registers();
  init_word_registers();
  init_composite_registers();
  init_shadow_registers();
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

unsigned char RegisterSet::read_a() {
  return a_register_->read();
}

unsigned char RegisterSet::read_b() {
  return b_register_->read();
}

unsigned char RegisterSet::read_c() {
  return c_register_->read();
}

unsigned char RegisterSet::read_d() {
  return d_register_->read();
}

unsigned char RegisterSet::read_e() {
  return e_register_->read();
}

unsigned char RegisterSet::read_f() {
  return f_register_->read();
}

unsigned char RegisterSet::read_h() {
  return h_register_->read();
}

unsigned char RegisterSet::read_l() {
  return l_register_->read();
}

unsigned short RegisterSet::read_af() {
  return af_register_->read();
}

unsigned short RegisterSet::read_bc() {
  return bc_register_->read();
}

unsigned short RegisterSet::read_de() {
  return de_register_->read();
}

unsigned short RegisterSet::read_hl() {
  return hl_register_->read();
}

unsigned short RegisterSet::read_ix() {
  return ix_register_->read();
}

unsigned short RegisterSet::read_iy() {
  return iy_register_->read();
}

unsigned short RegisterSet::read_pc() {
  return pc_register_->read();
}

unsigned short RegisterSet::read_sp() {
  return sp_register_->read();
}

unsigned short RegisterSet::read_r() {
  return r_register_->read();
}

void RegisterSet::write_a(const unsigned char value) {
  a_register_->write(value);
}

void RegisterSet::write_b(const unsigned char value) {
  b_register_->write(value);
}

void RegisterSet::write_c(const unsigned char value) {
  c_register_->write(value);
}

void RegisterSet::write_d(const unsigned char value) {
  d_register_->write(value);
}

void RegisterSet::write_e(const unsigned char value) {
  e_register_->write(value);
}

void RegisterSet::write_f(const unsigned char value) {
  f_register_->write(value);
}

void RegisterSet::write_h(const unsigned char value) {
  h_register_->write(value);
}

void RegisterSet::write_l(const unsigned char value) {
  l_register_->write(value);
}

void RegisterSet::write_af(const unsigned short value) {
  af_register_->write(value);
}

void RegisterSet::write_bc(const unsigned short value) {
  bc_register_->write(value);
}

void RegisterSet::write_de(const unsigned short value) {
  de_register_->write(value);
}

void RegisterSet::write_hl(const unsigned short value) {
  hl_register_->write(value);
}

void RegisterSet::write_ix(const unsigned short value) {
  ix_register_->write(value);
}

void RegisterSet::write_iy(const unsigned short value) {
  iy_register_->write(value);
}

void RegisterSet::write_pc(const unsigned short value) {
  pc_register_->write(value);
}

void RegisterSet::write_sp(const unsigned short value) {
  sp_register_->write(value);
}

void RegisterSet::write_r(const unsigned short value) {
  r_register_->write(value);
}

void RegisterSet::update_sign_flag(const bool value) {
  f_register_->update_sign_flag(value);
}

void RegisterSet::update_zero_flag(const bool value) {
  f_register_->update_zero_flag(value);
}

void RegisterSet::update_half_carry_flag(const bool value) {
  f_register_->update_half_carry_flag(value);
}

void RegisterSet::update_parity_flag(const bool value) {
  f_register_->update_parity_flag(value);
}

void RegisterSet::update_subtract_flag(const bool value) {
  f_register_->update_subtract_flag(value);
}

void RegisterSet::update_carry_flag(const bool value) {
  f_register_->update_carry_flag(value);
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

void RegisterSet::init_word_registers() {
  ix_register_ = new WordRegister();
  iy_register_ = new WordRegister();
  pc_register_ = new WordRegister();
  sp_register_ = new WordRegister(0xDFF0);
  r_register_ = new WordRegister();
}

void RegisterSet::init_composite_registers() {
  af_register_ = new CompositeRegister(a_register_, f_register_);
  bc_register_ = new CompositeRegister(b_register_, c_register_);
  de_register_ = new CompositeRegister(d_register_, e_register_);
  hl_register_ = new CompositeRegister(h_register_, l_register_);
}

void RegisterSet::init_shadow_registers() {
  af_shadow_register_ = new WordRegister();
  bc_shadow_register_ = new WordRegister();
  de_shadow_register_ = new WordRegister();
  hl_shadow_register_ = new WordRegister();
}

RegisterSet::~RegisterSet() {
  delete a_register_;
  delete b_register_;
  delete c_register_;
  delete d_register_;
  delete e_register_;
  delete f_register_;
  delete h_register_;
  delete l_register_;

  delete af_register_;
  delete bc_register_;
  delete de_register_;
  delete hl_register_;

  delete ix_register_;
  delete iy_register_;

  delete pc_register_;
  delete sp_register_;
  delete r_register_;

  delete af_shadow_register_;
  delete bc_shadow_register_;
  delete de_shadow_register_;
  delete hl_shadow_register_;
}
