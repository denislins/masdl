#pragma once

#include "memory_control_register.h"

namespace masdl {
  namespace memory {
    class Memory {
      public:
        Memory();

        unsigned char read(const unsigned short address);
        void write(const unsigned short address, const unsigned char value);

      private:
        unsigned char rom_[0x100000];
        unsigned char ram_[0x4000];
        unsigned char ram_banks_[2][0x4000];

        unsigned char first_rom_bank_ = 0;
        unsigned char second_rom_bank_ = 0;
        unsigned char third_rom_bank_ = 0;

        MemoryControlRegister *control_register_;

        void write_to_ram(const unsigned short address, const unsigned char value);
        void page_memory(const unsigned short address, const unsigned char value);
    };
  };
};
