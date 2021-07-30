#pragma once

namespace masdl {
  namespace memory {
    class MemoryControlRegister {
      public:
        void write(const unsigned char value);
        bool is_ram_banking_enabled();
        unsigned char get_current_ram_bank();

      private:
        bool ram_banking_enabled_ = false;
        unsigned char current_ram_bank_ = 0;
    };
  };
};
