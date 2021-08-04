#pragma once

#include <SDL2/SDL.h>

namespace masdl {
  namespace screen {
    class Screen {
      public:
        Screen();
        ~Screen();

        void refresh();

      private:
        SDL_Window *window_;
        SDL_Renderer *renderer_;

        void init_window();
        void init_renderer();
    };
  };
};
