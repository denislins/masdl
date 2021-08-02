#include <iostream>
#include "emulator.h"

using namespace masdl;

int main(int argc, char* argv[]) {
  Emulator *e = new Emulator();

  if (e->boot() == false) {
    std::cout << "Failed to initialize\n";
    return 0;
  }

  std::cout << "Finished booting up\n";
  std::cout << "Emulation started\n";

  e->load();
  e->start();

  std::cout << "Emulation stopped\n";
};
