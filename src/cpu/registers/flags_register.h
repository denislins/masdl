#pragma once

#include "byte_register.h"

namespace masdl {
  namespace cpu {
    namespace registers {
      class FlagsRegister : public ByteRegister {
        public:
          void update_sign_flag(const bool value);
          void update_zero_flag(const bool value);
          void update_half_carry_flag(const bool value);
          void update_parity_flag(const bool value);
          void update_subtract_flag(const bool value);
          void update_carry_flag(const bool value);

        private:
          void update_flag(const char mask, const bool value);
      };
    };
  };
};
