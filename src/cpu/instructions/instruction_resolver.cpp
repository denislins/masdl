#include "instruction_resolver.h"

using namespace masdl::cpu::instructions;

InstructionResolver::InstructionResolver(Memory *memory, RegisterSet *registers) {
  memory_ = memory;
  registers_ = registers;
}
