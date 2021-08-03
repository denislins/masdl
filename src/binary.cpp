#include <iostream>
#include "emulator.h"

using namespace masdl;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "usage: masdl [rom_path]" << std::endl;
    return 1;
  }

  Emulator *emulator = new Emulator();

  if (emulator->boot() == false) {
    std::cout << "SDL failed to initialize" << std::endl;
    return 1;
  }

  if (emulator->load_rom(argv[1]) == false) {
    std::cout << "Invalid rom" << std::endl;
    return 1;
  }

  std::cout << "Emulation started: " << argv[1] << std::endl;

  emulator->start();

  std::cout << "Emulation stopped" << std::endl;
};
