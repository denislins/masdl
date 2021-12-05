#include "default_instruction_set.h"

using namespace masdl::cpu::instruction_sets;

DefaultInstructionSet::DefaultInstructionSet(Memory *memory, RegisterSet *registers) {
  memory_ = memory;
  registers_ = registers;
}

unsigned char DefaultInstructionSet::execute_instruction(unsigned char opcode) {
  return 8;
}
