#pragma once

#include "memory/memory.h"
#include "cpu/cpu.h"
#include "screen/screen.h"

namespace masdl {
  using namespace memory;
  using namespace cpu;
  using namespace screen;

  class Emulator {
    public:
      Emulator();
      ~Emulator();

      bool boot();
      bool load_rom(char *path);
      void start();

    private:
      const int MACHINE_CLOCKS_PER_CYCLE = 10738580 / 60;

      Memory *memory_;
      Cpu *cpu_;
      Screen *screen_;
      bool running_;

      void reset();
      void process_events();
      void render_frame();
  };
};
