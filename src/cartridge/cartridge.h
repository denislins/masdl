#pragma once

namespace masdl {
  namespace cartridge {
    class Cartridge {
      public:
        Cartridge(char *path);

        bool is_valid();
        unsigned char read_address(const unsigned short address);

      private:
        char *contents_;

        void read_file(char *path);
    };
  };
};
