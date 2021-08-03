#include <iostream>
#include <fstream>
#include "cartridge.h"

using namespace masdl::cartridge;

Cartridge::Cartridge(char *path) {
  read_file(path);
}

bool Cartridge::is_valid() {
  return contents_ != nullptr;
}

unsigned char Cartridge::read_address(const unsigned short address) {
  return (unsigned char) contents_[address];
}

void Cartridge::read_file(char *path) {
  std::ifstream file(path, std::ios::in | std::ios::binary | std::ios::ate);

  if (file.is_open() == false) {
    contents_ = nullptr;
    return;
  }

  std::streampos file_size = file.tellg();
  contents_ = new char[file_size];

  file.seekg(0, std::ios::beg);
  file.read(contents_, file_size);
  file.close();
}
