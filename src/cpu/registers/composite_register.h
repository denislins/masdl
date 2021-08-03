#pragma once

#include "byte_register.h"

namespace masdl {
  namespace cpu {
    namespace registers {
      class CompositeRegister {
        public:
          CompositeRegister(ByteRegister *register_a, ByteRegister *register_b);
          unsigned short read();
          void write(const unsigned short value);

        private:
          ByteRegister *register_a_;
          ByteRegister *register_b_;
      };
    };
  };
};
