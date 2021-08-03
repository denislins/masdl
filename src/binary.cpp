#include <iostream>
#include "emulator.h"

using namespace masdl;

int main(int argc, char* argv[]) {
  Emulator *emulator = new Emulator();

  if (emulator->boot() == false) {
    std::cout << "Failed to initialize\n";
    return 0;
  }

  std::cout << "Finished booting up\n";
  std::cout << "Emulation started\n";

  emulator->reset();
  emulator->start();

  std::cout << "Emulation stopped\n";
};
