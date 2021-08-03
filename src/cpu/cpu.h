#pragma once

#include "../memory/memory.h"
#include "registers/register_set.h"

using namespace masdl::memory;
using namespace masdl::cpu::registers;

namespace masdl {
  namespace cpu {
    class Cpu {
      public:
        Cpu(Memory *memory);

        void reset();
        char tick();

      private:
        Memory *memory_;
        RegisterSet *registers_;
    };
  };
};
