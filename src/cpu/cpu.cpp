#include "cpu.h"

using namespace masdl::cpu;

Cpu::Cpu(Memory *memory) {
  memory_ = memory;
  registers_ = new RegisterSet();
  resolver_ = new InstructionResolver(memory_, registers_);
}

void Cpu::reset() {
  registers_->reset();
}

char Cpu::tick() {
  const unsigned short address = registers_->read_pc();
  const unsigned char refresh = registers_->read_r();

  registers_->write_pc(address + 1);
  registers_->write_r(refresh + 1);

  // const unsigned char opcode = memory_->read(address);

  // execute_instruction(opcode);

  return 8;
}

Cpu::~Cpu() {
  delete resolver_;
  delete registers_;
}
