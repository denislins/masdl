#include <SDL2/SDL.h>
#include "emulator.h"

using namespace masdl;

Emulator::Emulator() {
  memory_ = new Memory();
  cpu_ = new Cpu(memory_);
  screen_ = new Screen();
}

bool Emulator::boot() {
  const int sdl_initialized = SDL_Init(SDL_INIT_EVERYTHING);

  if (sdl_initialized < 0) {
    return false;
  }

  return true;
};

void Emulator::load() {
  memory_->reset();
}

void Emulator::start() {
  running_ = true;

  while (running_) {
    process_events();

    const Uint64 start = SDL_GetPerformanceCounter();

    render_frame();

    const Uint64 end = SDL_GetPerformanceCounter();

    const double elapsed_time = (end - start) / (double) SDL_GetPerformanceFrequency() * 1000.0;
    const int delay_time = floor(16.666f - elapsed_time);

    SDL_Delay(delay_time);
  }
};

void Emulator::process_events() {
  SDL_Event event;

  while (SDL_PollEvent(&event) != 0) {
		switch (event.type) {
			case SDL_QUIT:
        running_ = false;
        break;
    }
  }
};

void Emulator::render_frame() {
  int frame_machine_cycles = 0;

  while (frame_machine_cycles < MACHINE_CLOCKS_PER_CYCLE) {
    const int cpu_cycles = 8;
    const int machine_cycles = cpu_cycles * 3;

    // const double vdp_cycles = machine_cycles / 2.0;

    // vdp.tick(vdp_cycles);
    // apu.tick(cpu_cycles);

    frame_machine_cycles += machine_cycles;
  }
};

Emulator::~Emulator() {
  SDL_Quit();
}
