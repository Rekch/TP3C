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
  else if(game->player.slowingDown && !game->player.onLedge) // saut idle
  {
    SDL_Rect srcRect_player = { game->player.animFrame*game->player.w, 384, game->player.w, game->player.h };
    SDL_Rect rect_player = { game->player.x, game->player.y, game->player.w, game->player.h };
    SDL_RenderCopyEx(game->renderer, game->playerTexture,
        &srcRect_player, &rect_player, 0, NULL, 0 );
  }
  else if(!game->player.slowingDown && !game->player.onLedge && !game->player.facingLeft) // saut droit
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
    else if(!game->player.slowingDown && !game->player.onLedge && game->player.facingLeft) // saut gauche
  {
    SDL_Rect srcRect_player = { game->player.animFrame*game->player.w, 640, game->player.w, game->player.h };
    SDL_Rect rect_player = { game->player.x, game->player.y, game->player.w, game->player.h };
    SDL_RenderCopyEx(game->renderer, game->playerTexture,
        &srcRect_player, &rect_player, 0, NULL, 0 );
  }  

}

void doRender(GameState *game)
{
  //couleur -> bleu
  SDL_SetRenderDrawColor(game->renderer, 128, 128, 255, 255);

  //clear l'écran (bleu)
  SDL_RenderClear(game->renderer);

  //couleur -> blanc
  SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);

  SDL_RenderCopy(game->renderer, game->backgroundTexture, NULL, NULL);


  doRenderLedges(game);
  doRenderDonut(game);
  doRenderPlayer(game);


  //affiche à l'écran ce qui a été généré
  SDL_RenderPresent(game->renderer);
}

void initSDL(GameState *gameState){

  SDL_Window *window = NULL;                    // Declare une fenetre
  SDL_Renderer *renderer = NULL;                // Declare renderer

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);              // Initialise SDL2

  //crée une fenêtre avec config suivante
  window = SDL_CreateWindow("Game Window",                     // window title
      SDL_WINDOWPOS_UNDEFINED,           // initial x position
      SDL_WINDOWPOS_UNDEFINED,           // initial y position
      SCREEN_WIDTH,                               // width, en pixels
      SCREEN_HEIGHT,                               // height, en pixels
      0                                  // flags
      );
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  gameState->window = window;
  gameState->renderer = renderer;
}

void gameLoop(GameState *gameState, int levelMAX)
{
  // fenetre ouverte: entre dans la boucle du jeu ( SDL_PollEvent)
  SetStageNum(gameState,1);
  loadGame(gameState);

  /** 
   * 0 = playing current level
   * 1 = won current level
   */
  int done;
  
  while(gameState->stageNum <= levelMAX)
  {
    done = 0;
    //boucle evenement
    while(!done)
    {
      //check evenements
      collisionDetect(gameState);

      done = processEvents(gameState);

      process(gameState);

      //Render display
      doRender(gameState);
    }

    if(done == 1) {  
        printf("You Won\n");
        break;    
    }
    destroyLevel(gameState);
    loadGame(gameState);
  }
}

void destroyLevel(GameState *gameState){

  //Shutdown game and unload all memory
  free(gameState->ledges);
  free(gameState->donuts);



  //SDL_DestroyTexture(gameState.star);
  SDL_DestroyTexture(gameState->sheetTexture);
  SDL_DestroyTexture(gameState->donutTexture);
  SDL_DestroyTexture(gameState->playerTexture);
  SDL_DestroyTexture(gameState->backgroundTexture);
}

void destroySDL(GameState *gameState){


  // fermeture fenetre
  SDL_DestroyWindow(gameState->window);
  SDL_DestroyRenderer(gameState->renderer);

  // termine prog
  SDL_Quit();
}
