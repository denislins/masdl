#pragma once

#include "byte_register.h"
#include "flags_register.h"

namespace masdl {
  namespace cpu {
    namespace registers {
      class RegisterSet {
        public:
          RegisterSet();
          void reset();

        private:
          ByteRegister *a_register_;
          ByteRegister *b_register_;
          ByteRegister *c_register_;
          ByteRegister *d_register_;
          ByteRegister *e_register_;
          ByteRegister *h_register_;
          ByteRegister *l_register_;

          FlagsRegister *flags_register_;

          void init_byte_registers();
      };
    };
  };
};
