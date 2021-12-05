#pragma once

#include "../../memory/memory.h"
#include "../registers/register_set.h"

using namespace masdl::memory;
using namespace masdl::cpu::registers;

namespace masdl {
  namespace cpu {
    namespace instruction_sets {
      class DefaultInstructionSet {
        public:
          DefaultInstructionSet(Memory *memory, RegisterSet *registers);

          unsigned char execute_instruction(unsigned char opcode);

        private:
          Memory *memory_;
          RegisterSet *registers_;
      };
    };
  };
};
