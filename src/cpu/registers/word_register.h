#pragma once

namespace masdl {
  namespace cpu {
    namespace registers {
      class WordRegister {
        public:
          WordRegister();
          WordRegister(const unsigned short default_value);

          void reset();
          unsigned short read();
          void write(const unsigned short value);

        private:
          unsigned short default_value_;
          unsigned short value_;
      };
    };
  };
};
