#include "cpu.h"

using namespace masdl::cpu;
using namespace masdl::cpu::registers;

Cpu::Cpu(Memory *memory) {
  memory_ = memory;
  registers_ = new RegisterSet();
}

void Cpu::reset() {
  registers_->reset();
}

char Cpu::tick() {
  const unsigned short address = registers_->read_pc();
  registers_->write_pc(address + 1);

  // const unsigned char opcode = memory_->read(address);

  return 8;
}
