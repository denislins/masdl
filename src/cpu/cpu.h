#pragma once

#include "../memory/memory.h"
#include "registers/register_set.h"
#include "instruction_sets/default_instruction_set.h"

using namespace masdl::memory;
using namespace masdl::cpu::registers;
using namespace masdl::cpu::instruction_sets;

namespace masdl {
  namespace cpu {
    class Cpu {
      public:
        Cpu(Memory *memory);
        ~Cpu();

        void reset();
        unsigned char tick();

      private:
        Memory *memory_;
        RegisterSet *registers_;
        DefaultInstructionSet *default_instruction_set_;

        unsigned char execute_instruction(unsigned char opcode);
    };
  };
};
