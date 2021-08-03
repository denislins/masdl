#pragma once

namespace masdl {
  namespace cpu {
    namespace registers {
      class WordRegister {
        public:
          void reset();
          unsigned short read();
          void write(const unsigned short value);

        private:
          unsigned short value_;
      };
    };
  };
};
