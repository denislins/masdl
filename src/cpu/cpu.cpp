#include "cpu.h"

using namespace masdl::cpu;

Cpu::Cpu(Memory *memory) {
  memory_ = memory;
  registers_ = new RegisterSet();
  default_instruction_set_ = new DefaultInstructionSet(memory_, registers_);
}

void Cpu::reset() {
  registers_->reset();
}

unsigned char Cpu::tick() {
  const unsigned short address = registers_->read_pc();
  const unsigned char refresh = registers_->read_r();

  registers_->write_pc(address + 1);
  registers_->write_r(refresh + 1);

  const unsigned char opcode = memory_->read(address);

  return execute_instruction(opcode);;
}

unsigned char Cpu::execute_instruction(unsigned char opcode) {
  return default_instruction_set_->execute_instruction(opcode);
}

Cpu::~Cpu() {
  delete default_instruction_set_;
  delete registers_;
}
