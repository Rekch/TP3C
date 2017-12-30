#include "prototypes.h"

void victory(GameState *game){

    SDL_Event event;

  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_WINDOWEVENT_CLOSE:
        {
          if(game->window)
          {
            SDL_DestroyWindow(game->window);
            game->window = NULL;
            exit(0);
          }
        }
        break;
      case SDL_KEYDOWN:
        {
          switch(event.key.keysym.sym)
          {
            case SDLK_ESCAPE:
              exit(0);
              break;
          }
        }
        break;
      case SDL_QUIT:
        exit(0);
        break;
    }
  }

}
