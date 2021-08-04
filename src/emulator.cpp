#include <stdexcept>
#include <SDL2/SDL.h>
#include "emulator.h"
#include "cartridge/cartridge.h"

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

bool Emulator::load_rom(const char* path) {
  reset();

  cartridge_ = new Cartridge(path);

  if (cartridge_->is_valid() == false) {
    return false;
  }

  memory_->load_cartridge(cartridge_);

  return true;
}

void Emulator::start() {
  if (cartridge_ == nullptr || cartridge_->is_valid() == false) {
    throw std::runtime_error("No game to emulate");
  }

  running_ = true;

  while (running_) {
    run_cycle();
  }
};

void Emulator::reset() {
  if (cartridge_ != nullptr) {
    delete cartridge_;
  }

  memory_->reset();
  cpu_->reset();
}

void Emulator::run_cycle() {
  process_events();

  const Uint64 start = SDL_GetPerformanceCounter();

  render_frame();

  const Uint64 end = SDL_GetPerformanceCounter();

  const double elapsed_time = (end - start) / (double) SDL_GetPerformanceFrequency() * 1000.0;
  const short delay_time = floor(16.666f - elapsed_time);

  SDL_Delay(delay_time);
}

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
  unsigned long frame_machine_cycles = 0;

  while (frame_machine_cycles < MACHINE_CLOCKS_PER_CYCLE) {
    const char cpu_cycles = cpu_->tick();
    const char machine_cycles = cpu_cycles * 3;

    // const double vdp_cycles = machine_cycles / 2.0;

    // vdp.tick(vdp_cycles);
    // apu.tick(cpu_cycles);

    frame_machine_cycles += machine_cycles;
  }
};

Emulator::~Emulator() {
  delete screen_;
  delete cpu_;
  delete memory_;

  if (cartridge_ != nullptr) {
    delete cartridge_;
  }

  SDL_Quit();
}
