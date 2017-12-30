#include "prototypes.h"

void initMenu(GameState *game,int choice){
    setLevelBackground(game, "assets/background.png");
    

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
            case SDLK_UP:
              choice=1;
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
