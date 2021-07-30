#pragma once

#include "memory/memory.h"

namespace masdl {
  using namespace memory;

  class Emulator {
    public:
      Emulator();
      ~Emulator();

      bool boot();
      void load();
      void start();

    private:
      const int MACHINE_CLOCKS_PER_CYCLE = 10738580 / 60;

      Memory *memory_;
      bool running_;

      void process_events();
      void render_frame();
  };
};
