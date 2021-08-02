#pragma once

namespace masdl {
  namespace cpu {
    namespace registers {
      class ByteRegister {
        public:
          void reset();
          unsigned char read();
          void write(const unsigned char value);

        private:
          unsigned char value_;
      };
    };
  };
};
