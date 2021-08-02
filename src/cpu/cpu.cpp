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
