#include "emulator.h"

using namespace masdl;

int main(int argc, char* argv[]) {
  Emulator *e = new Emulator();
  e->boot();
}