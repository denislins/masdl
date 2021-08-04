#pragma once

#include "../memory/memory.h"
#include "registers/register_set.h"
#include "instructions/instruction_resolver.h"

using namespace masdl::memory;
using namespace masdl::cpu::registers;
using namespace masdl::cpu::instructions;

namespace masdl {
  namespace cpu {
    class Cpu {
      public:
        Cpu(Memory *memory);
        ~Cpu();

        void reset();
        char tick();

      private:
        Memory *memory_;
        RegisterSet *registers_;
        InstructionResolver *resolver_;
    };
  };
};
