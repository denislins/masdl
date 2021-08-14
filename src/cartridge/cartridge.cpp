#include <iostream>
#include <fstream>
#include "cartridge.h"

using namespace masdl::cartridge;

Cartridge::Cartridge(const char* path) {
  read_file(path);
}

bool Cartridge::is_valid() {
  return contents_ != nullptr;
}

unsigned char Cartridge::read_address(const unsigned short address) {
  return (unsigned char) contents_[address];
}

void Cartridge::read_file(const char* path) {
  std::ifstream file(path, std::ios::in | std::ios::binary | std::ios::ate);

  if (file.is_open() == false) {
    contents_ = nullptr;
    return;
  }

  const std::streampos file_size = file.tellg();
  contents_ = new char[file_size];

  short start_position = 0;

  // strip off header in case rom was dumped using a mega drive cartridge
  // http://www.smspower.org/forums/viewtopic.php?t=7999&highlight=header+512
  if (file_size % 0x4000) {
    start_position = 512;
  }

  file.seekg(start_position, std::ios::beg);
  file.read(contents_, file_size);
  file.close();
}

Cartridge::~Cartridge() {
  if (contents_ != nullptr) {
    delete[] contents_;
  }
}
