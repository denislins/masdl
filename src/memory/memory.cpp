#include "memory.h"

using namespace masdl::memory;

Memory::Memory() {
  control_register_ = new MemoryControlRegister();
};

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
  if (address < 0x400) {
    return rom_[address];
  }

  if (address < 0x4000) {
    unsigned int mapped_address = address + (0x4000 * first_rom_bank_);
    return rom_[mapped_address];
  }

  if (address < 0x8000) {
    unsigned int mapped_address = address + (0x4000 * second_rom_bank_) - 0x4000;
    return rom_[mapped_address];
  }

  if (address < 0xC000) {
    if (control_register_->is_ram_banking_enabled() == true) {
      const unsigned char current_ram_bank = control_register_->get_current_ram_bank();
      return ram_banks_[current_ram_bank][address - 0x8000];
    }

    unsigned int mapped_address = address + (0x4000 * third_rom_bank_) - 0x8000;
    return rom_[mapped_address];
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
