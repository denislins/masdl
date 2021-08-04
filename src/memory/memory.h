#pragma once

#include "memory_control_register.h"
#include "../cartridge/cartridge.h"

namespace masdl {
  using namespace cartridge;

  namespace memory {
    class Memory {
      public:
        Memory();

        void reset();
        void load_cartridge(Cartridge *cartridge);
        unsigned char read(const unsigned short address);
        void write(const unsigned short address, const unsigned char value);

      private:
        Cartridge *cartridge_ = nullptr;

        unsigned char ram_[0x4000];
        unsigned char ram_banks_[2][0x4000];

        unsigned char first_rom_bank_;
        unsigned char second_rom_bank_;
        unsigned char third_rom_bank_;

        MemoryControlRegister *control_register_;

        void write_to_ram(const unsigned short address, const unsigned char value);
        void page_memory(const unsigned short address, const unsigned char value);
        unsigned char read_from_rom(const unsigned short address);
    };
  };
};
