#pragma once

#include "../memory/memory.h"

using namespace masdl::memory;

namespace masdl {
  namespace cpu {
    class Cpu {
      public:
        Cpu(Memory *memory);
        void reset();

      private:
        Memory *memory_;
    };
  };
};
