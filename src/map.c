#include "prototypes.h"

int Ledge_getX (Ledge  *l)
{
	return l->x;
}


int game_getLedgeX(GameState *game, int i)
{
  return Ledge_getX(&game->ledges[i]);
}




void loadMap(char *name, GameState *game)
{
  int** tile = createArray(game->mapDimX, game->mapDimY);
  int i=0;
  int k=0;

  int x, y;
  FILE *fp;

  fp = fopen(name, "r");

  if (fp == NULL)
  {
    printf("Erreur de lecture de la map %s\n", name);

    exit(1);
  }

  for (y=0;y<game->mapDimY;y++)
  {
    for (x=0;x<game->mapDimX;x++)
    {
      fscanf(fp, "%d", &tile[y][x]);
      if (tile[y][x] == 1) {game->nbLedges++;}
      if (tile[y][x] == 2) {game->nbDonuts++;} 

    }
  }

  game->ledges = (Ledge*) malloc(game->nbLedges*sizeof(Ledge)); 
  game->donuts= (Donut*) malloc(game->nbDonuts*sizeof(Donut)); 

  for (y=0;y<game->mapDimY;y++)
  {
    for (x=0;x<game->mapDimX;x++)
    {
      if (tile[y][x] == 1)  
      {
        game->ledges[i].w = 128;
        game->ledges[i].h = 128;
        game->ledges[i].x = x*128;
        game->ledges[i].y = y*128;
        game->ledges[i].ledgeType = tile[y][x];
        i++;
      }

      if (tile[y][x] == 2)  
      {
        game->donuts[k].w = 128;
        game->donuts[k].h = 128;
        game->donuts[k].x = x*128;
        game->donuts[k].y = y*128;
        game->donuts[k].display = 1;
        k++;
      }
    }
  }


  fclose(fp);
  destroyArray(tile);
}

void initLevel(GameState *game, int level)
{
  game->nbLedges = 0;
  game->nbDonuts = 0;
  game->mapGravity = 0.55;
  game->mapDimX = 10;
  game->mapDimY = 6;
  game->time = 0;
  
 
    setLevelBackground(game, "assets/background.png");
    initPlayerLevel(&game->player);
 
}

void updatePlayerPosition(GameState *game)
{
  Player *player = &game->player;
  player->x += player->dx;
  player->y += player->dy;
  player->animFrame %=32;
  player->animFrame++;
  player->dy += game->mapGravity;
  
}

void updateDonut(GameState *game)
{
    for(int i=0;i<game->nbDonuts;i++){
        Donut *donut = &game->donuts[i];
        donut->animFrame %=32;
        donut->animFrame++;
    }
  
}


void SetStageNum(GameState *game, int stageNum)
{
  game->stageNum = stageNum;
}

void loadGame(GameState *game)
{


  SDL_Surface *surface = NULL;
  game->sheetTexture = SDL_CreateTexture(game->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 128, 128);
  surface = IMG_Load("assets/character.png");
  
  if(surface == NULL)
  {
    printf("Cannot find character.png !\n\n");
    SDL_Quit();
    exit(1);
  }
  
  game->playerTexture = SDL_CreateTextureFromSurface(game->renderer, surface);
  SDL_FreeSurface(surface);

  surface = NULL;
  surface = IMG_Load("assets/donut.png");
  
  if(surface == NULL)
  {
    printf("Cannot find donut.png !\n\n");
    SDL_Quit();
    exit(1);
  }
  
  game->donutTexture = SDL_CreateTextureFromSurface(game->renderer, surface);
  SDL_FreeSurface(surface);



  initLevel(game,game->stageNum);

  char levelPath[20];
  sprintf(levelPath,"levels/level%d",game->stageNum);

  loadMap(levelPath,game);
}

void process(GameState *game)
{

  updatePlayerPosition(game);
  updateDonut(game);
  game->time++;
}




void setLevelBackground(GameState *game, char* bgImagePath){
  SDL_Surface *bg = IMG_Load(bgImagePath);
  game->backgroundTexture = SDL_CreateTextureFromSurface(game->renderer, bg);
  SDL_FreeSurface(bg);
}


