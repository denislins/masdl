#pragma once

namespace masdl {
  namespace memory {
    class MemoryControlRegister {
      public:
        void reset();
        void write(const unsigned char value);
        bool is_ram_banking_enabled();
        unsigned char get_current_ram_bank();

      private:
        bool ram_banking_enabled_;
        unsigned char current_ram_bank_;
    };
  };
};
