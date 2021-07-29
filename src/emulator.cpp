#include <iostream>
#include <SDL2/SDL.h>
#include "emulator.h"

using namespace masdl;

Emulator::Emulator() {
  std::cout << "emulator initialized\n";
};

void Emulator::boot() {
  int sdl_result = SDL_Init(SDL_INIT_VIDEO);

  if (sdl_result > -1) {
    std::cout << "SDL initialized\n";
    SDL_Quit();
  } else {
    std::cout << "SDL failed to initialize\n";
  }
};