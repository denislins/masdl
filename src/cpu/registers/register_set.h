#pragma once

#include "byte_register.h"
#include "flags_register.h"
#include "composite_register.h"
#include "word_register.h"

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
          FlagsRegister *f_register_;
          ByteRegister *h_register_;
          ByteRegister *l_register_;

          CompositeRegister *af_register_;
          CompositeRegister *bc_register_;
          CompositeRegister *de_register_;
          CompositeRegister *hl_register_;

          WordRegister *pc_register_;
          WordRegister *sp_register_;
          WordRegister *r_register_;

          void init_byte_registers();
          void init_composite_registers();
          void init_word_registers();
      };
    };
  };
};
