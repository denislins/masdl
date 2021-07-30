#pragma once

namespace masdl {
  class Emulator {
    public:
      bool boot();
      void start();
      void stop();

    private:
      const int MACHINE_CLOCKS_PER_CYCLE = 10738580 / 60;

      bool running_;

      void process_events();
      void render_frame();
  };
};
