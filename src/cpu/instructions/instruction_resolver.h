#pragma once

#include "../../memory/memory.h"
#include "../registers/register_set.h"

using namespace masdl::memory;
using namespace masdl::cpu::registers;

namespace masdl {
  namespace cpu {
    namespace instructions {
      class InstructionResolver {
        public:
          InstructionResolver(Memory *memory, RegisterSet *registers);

        private:
          Memory *memory_;
          RegisterSet *registers_;
      };
    };
  };
};
