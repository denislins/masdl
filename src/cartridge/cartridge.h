#pragma once

namespace masdl {
  namespace cartridge {
    class Cartridge {
      public:
        Cartridge(const char* path);
        ~Cartridge();

        bool is_valid();
        unsigned char read_address(const unsigned short address);

      private:
        char *contents_ = nullptr;

        void read_file(const char* path);
    };
  };
};
