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
          ~RegisterSet();

          void reset();

          unsigned char read_a();
          unsigned char read_b();
          unsigned char read_c();
          unsigned char read_d();
          unsigned char read_e();
          unsigned char read_f();
          unsigned char read_h();
          unsigned char read_l();

          unsigned short read_af();
          unsigned short read_bc();
          unsigned short read_de();
          unsigned short read_hl();

          unsigned short read_ix();
          unsigned short read_iy();

          unsigned short read_pc();
          unsigned short read_sp();
          unsigned short read_r();

          void write_a(const unsigned char value);
          void write_b(const unsigned char value);
          void write_c(const unsigned char value);
          void write_d(const unsigned char value);
          void write_e(const unsigned char value);
          void write_f(const unsigned char value);
          void write_h(const unsigned char value);
          void write_l(const unsigned char value);

          void write_af(const unsigned short value);
          void write_bc(const unsigned short value);
          void write_de(const unsigned short value);
          void write_hl(const unsigned short value);

          void write_ix(const unsigned short value);
          void write_iy(const unsigned short value);

          void write_pc(const unsigned short value);
          void write_sp(const unsigned short value);
          void write_r(const unsigned short value);

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

          WordRegister *ix_register_;
          WordRegister *iy_register_;

          WordRegister *pc_register_;
          WordRegister *sp_register_;
          WordRegister *r_register_;

          WordRegister *af_shadow_register_;
          WordRegister *bc_shadow_register_;
          WordRegister *de_shadow_register_;
          WordRegister *hl_shadow_register_;

          void init_byte_registers();
          void init_composite_registers();
          void init_word_registers();
          void init_shadow_registers();
      };
    };
  };
};
