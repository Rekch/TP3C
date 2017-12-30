#include "prototypes.h"

int processEvents(GameState *game){

  SDL_Event event;
  int done = 0;

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


  const Uint8 *state = SDL_GetKeyboardState(NULL);

if(state[SDL_SCANCODE_LEFT])
    {
      game->player.dx -= 0.2;
     
      game->player.facingLeft = 1;
      game->player.slowingDown = 0; 
      game->player.walking = 1;
    }
    else if(state[SDL_SCANCODE_RIGHT])
    {
      game->player.dx += 0.2;
      game->player.facingLeft = 0;
      game->player.slowingDown = 0;
      game->player.walking = 1;
    }
    else
    {
      game->player.animFrame = 0;

      game->player.dx *= 0;

      game->player.slowingDown = 1; 
      game->player.walking = 0;

     
}
if(state[SDL_SCANCODE_UP] && (game->player.onLedge))
    {
      game->player.dy = -8;
      game->player.onLedge = 0;
    }


  if(game->player.playerDonut == game->nbDonuts ){
    done = 2;
  }

  if( game->player.x > SCREEN_WIDTH || game->player.x < 0 
      || game->player.y > SCREEN_HEIGHT) {
    done = 1;
  }

  return done;
}

void doRenderLedges(GameState *game)
{

  for(int i = 0; i < game->nbLedges; i++)
  {
      SDL_Rect srcRect_ledges = { 0, 0, game->ledges[i].w, game->ledges[i].h };
      SDL_Rect Rect_ledges = { game->ledges[i].x, game->ledges[i].y, game->ledges[i].w, game->ledges[i].h };
      SDL_RenderCopyEx(game->renderer, game->sheetTexture,  & srcRect_ledges, & Rect_ledges,0, NULL, 0);   
  }
}




void doRenderDonut(GameState *game)
{
  for(int i = 0; i < game->nbDonuts; i++)
  {
    if(game->donuts[i].display == 1)
    {
      SDL_Rect srcRect_donut = { game->donuts[i].animFrame*128, 0, game->ledges[i].w, game->ledges[i].h };
      SDL_Rect Rect_donut = { game->donuts[i].x, game->donuts[i].y, game->donuts[i].w, game->donuts[i].h};
      SDL_RenderCopyEx(game->renderer, game->donutTexture,  &srcRect_donut, &Rect_donut,0, NULL, 0);
    }
  }
}


void doRenderPlayer(GameState *game)
{

  if(game->player.slowingDown )
  {
    SDL_Rect srcRect_player = { game->player.animFrame*game->player.w, 256, game->player.w, game->player.h };
    SDL_Rect rect_player = { game->player.x, game->player.y, game->player.w, game->player.h };
    SDL_RenderCopyEx(game->renderer, game->playerTexture, &srcRect_player, &rect_player, 0, NULL, 0  );
  }
  else if(!game->player.slowingDown && game->player.onLedge && !game->player.facingLeft)
  {
    SDL_Rect srcRect_player = { game->player.animFrame*128, 0, game->player.w, game->player.h };
    SDL_Rect rect_player = { game->player.x, game->player.y, game->player.w, game->player.h};
    SDL_RenderCopyEx(game->renderer, game->playerTexture,&srcRect_player, &rect_player, 0, NULL, 0  );
  }
  else if(game->player.slowingDown && !game->player.onLedge) 
  {
    SDL_Rect srcRect_player = { game->player.animFrame*game->player.w, 384, game->player.w, game->player.h };
    SDL_Rect rect_player = { game->player.x, game->player.y, game->player.w, game->player.h };
    SDL_RenderCopyEx(game->renderer, game->playerTexture,
        &srcRect_player, &rect_player, 0, NULL, 0 );
  }
  else if(!game->player.slowingDown && !game->player.onLedge && !game->player.facingLeft) 
  {
    SDL_Rect srcRect_player = { game->player.animFrame*game->player.w, 512, game->player.w, game->player.h };
    SDL_Rect rect_player = { game->player.x, game->player.y, game->player.w, game->player.h };
    SDL_RenderCopyEx(game->renderer, game->playerTexture,
        &srcRect_player, &rect_player, 0, NULL, 0 );
  }
    else if(!game->player.slowingDown && game->player.onLedge && game->player.facingLeft)
  {
    SDL_Rect srcRect_player = { game->player.animFrame*128, 128, game->player.w, game->player.h };
    SDL_Rect rect_player = { game->player.x, game->player.y, game->player.w, game->player.h};
    SDL_RenderCopyEx(game->renderer, game->playerTexture,&srcRect_player, &rect_player, 0, NULL, 0  );
  }
    else if(!game->player.slowingDown && !game->player.onLedge && game->player.facingLeft) 
  {
    SDL_Rect srcRect_player = { game->player.animFrame*game->player.w, 640, game->player.w, game->player.h };
    SDL_Rect rect_player = { game->player.x, game->player.y, game->player.w, game->player.h };
    SDL_RenderCopyEx(game->renderer, game->playerTexture,
        &srcRect_player, &rect_player, 0, NULL, 0 );
  }  

}

void doRender(GameState *game)
{
  
  SDL_SetRenderDrawColor(game->renderer, 128, 128, 255, 255);

  
  SDL_RenderClear(game->renderer);

  
  SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);

  SDL_RenderCopy(game->renderer, game->backgroundTexture, NULL, NULL);


  doRenderLedges(game);
  doRenderDonut(game);
  doRenderPlayer(game);


  
  SDL_RenderPresent(game->renderer);
}

void initSDL(GameState *gameState){

  SDL_Window *window = NULL;                    
  SDL_Renderer *renderer = NULL;                

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);              

  
  window = SDL_CreateWindow("Le ramasseur de donut",                     
      SDL_WINDOWPOS_UNDEFINED,           
      SDL_WINDOWPOS_UNDEFINED,           
      SCREEN_WIDTH,                               
      SCREEN_HEIGHT,                               
      0                                  
      );
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  gameState->window = window;
  gameState->renderer = renderer;
}

void gameLoop(GameState *gameState, int levelMAX)
{
  
  SetStageNum(gameState,1);
  loadGame(gameState);

  int done;
  
  while(gameState->stageNum <= levelMAX)
  {
    done = 0;
    
    while(!done)
    {
      
      collisionDetect(gameState);

      done = processEvents(gameState);

      process(gameState);

      doRender(gameState);
    }

    if(done == 1) {  
        printf("Vous avez gagné!\n");
        break;    
    }
    destroyLevel(gameState);
    loadGame(gameState);
  }
}

void destroyLevel(GameState *gameState){

 
  free(gameState->ledges);
  free(gameState->donuts);


  SDL_DestroyTexture(gameState->sheetTexture);
  SDL_DestroyTexture(gameState->donutTexture);
  SDL_DestroyTexture(gameState->playerTexture);
  SDL_DestroyTexture(gameState->backgroundTexture);
}

void destroySDL(GameState *gameState){


  
  SDL_DestroyWindow(gameState->window);
  SDL_DestroyRenderer(gameState->renderer);

  
  SDL_Quit();
}
