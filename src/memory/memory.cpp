#include <iostream>
#include "memory.h"

using namespace masdl::memory;

Memory::Memory() {
  control_register_ = new MemoryControlRegister();
};

void Memory::reset() {
  memset(ram_, 0, sizeof(ram_));
  memset(ram_banks_, 0, sizeof(ram_banks_));

  first_rom_bank_ = 0;
  second_rom_bank_ = 0;
  third_rom_bank_ = 0;

  control_register_->reset();
}

void Memory::load_cartridge(Cartridge *cartridge) {
  if (cartridge_ != nullptr) {
    delete cartridge_;
  }

  cartridge_ = cartridge;
}

void Memory::write(const unsigned short address, const unsigned char value) {
  if (address < 0x8000) {
    // can't write to rom
    return;
  }

  if (address < 0xC000) {
    if (control_register_->is_ram_banking_enabled()) {
      const unsigned char current_ram_bank = control_register_->get_current_ram_bank();
      ram_banks_[current_ram_bank][address - 0x8000] = value;
    }

    // can't write to rom
    return;
  }

  write_to_ram(address, value);

  if (address >= 0xFFFC) {
    page_memory(address, value);
  }
}

unsigned char Memory::read(const unsigned short address) {
  if (address < 0x8000) {
    return read_from_rom(address);
  }

  if (address < 0xC000) {
    if (control_register_->is_ram_banking_enabled() == false) {
      return read_from_rom(address);
    }

    const unsigned char current_ram_bank = control_register_->get_current_ram_bank();
    return ram_banks_[current_ram_bank][address - 0x8000];
  }

  return ram_[address];
}

void Memory::write_to_ram(const unsigned short address, const unsigned char value) {
  const unsigned short mapped_address = address - 0xC000;

  ram_[mapped_address] = value;

  // handle mirroring
  if (mapped_address < 0x1FFC) {
    ram_[mapped_address + 0x2000] = value;
  } else if (mapped_address >= 0x2000) {
    ram_[mapped_address - 0x2000] = value;
  }
}

void Memory::page_memory(const unsigned short address, const unsigned char value) {
  const unsigned char bank = value & 0x1F;

  switch(address) {
    case 0xFFFC:
      control_register_->write(value);
      break;

    case 0xFFFD:
      first_rom_bank_ = bank;
      break;

    case 0xFFFE:
      second_rom_bank_ = bank;
      break;

    case 0xFFFF:
      if (control_register_->is_ram_banking_enabled() == false) {
        third_rom_bank_ = bank;
      }
      break;
  }
}

unsigned char Memory::read_from_rom(const unsigned short address) {
  if (address < 0x400) {
    return cartridge_->read_address(address);
  }

  unsigned short mapped_address;

  if (address < 0x4000) {
    mapped_address = address + (0x4000 * first_rom_bank_);
  } else if (address < 0x8000) {
    mapped_address = address + (0x4000 * second_rom_bank_) - 0x4000;
  } else {
    mapped_address = address + (0x4000 * third_rom_bank_) - 0x8000;
  }

  return cartridge_->read_address(mapped_address);
}
