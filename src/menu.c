#include "prototypes.h"

int initMenu(GameState *game){
   /* SDL_Surface *jouer = NULL;
    SDL_Rect posJouer; 
    
    jouer=IMG_Load("assets/jouer.png");
    posJouer.x=640;
    posJouer.y=360;
*/
  SDL_SetRenderDrawColor(game->renderer, 128, 128, 255, 255);

  
  SDL_RenderClear(game->renderer);

  
  SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);

  SDL_RenderCopy(game->renderer, game->backgroundTexture, NULL, NULL);

  SDL_RenderPresent(game->renderer);

    SDL_Event event;
    int go;
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
            case SDLK_RETURN:
              go=1;
              break;
          }
        }
        break;
      case SDL_QUIT:
        exit(0);
        break;
    }
  }
return  go;

}

 
