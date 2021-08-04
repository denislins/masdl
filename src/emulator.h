#pragma once

#include "memory/memory.h"
#include "cpu/cpu.h"
#include "screen/screen.h"
#include "cartridge/cartridge.h"

namespace masdl {
  using namespace memory;
  using namespace cpu;
  using namespace screen;
  using namespace cartridge;

  class Emulator {
    public:
      Emulator();
      ~Emulator();

      bool boot();
      bool load_rom(const char* path);
      void start();

    private:
      const int MACHINE_CLOCKS_PER_CYCLE = 10738580 / 60;

      Memory *memory_;
      Cpu *cpu_;
      Screen *screen_;
      Cartridge *cartridge_;
      bool running_;

      void reset();
      void run_cycle();
      void process_events();
      void render_frame();
  };
};
