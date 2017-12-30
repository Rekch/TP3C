#ifndef PROTOTYPES
#define PROTOTYPES
 
#include "structs.h"


extern void initMenu(GameState *game,int choice);
extern void victory(GameState *game);

/**
 @fn int collide2d(float x1, float y1, float x2, float y2, float wt1, float ht1, float wt2, float ht2)
 @brief collide2d: "fonction de collision en entre le joueur les ledges" 
 @param [in] x1 y1 x2 y2 wt1 ht1 wt2 ht2 de type float 
 @return int
 */
extern int collide2d(float x1, float y1, float x2, float y2, float wt1, float ht1, float wt2, float ht2);
 

extern int** createArray(int m, int n);

/**
 @fn void destroyArray(int** arr)
 @param arr double pointeur(tableau 2D)
 @return void
 */
extern void destroyArray(int** arr); 

extern int ledge_getX (Ledge * l);
extern int game_getLedgeX(GameState *game, int i);

extern void initSDL(GameState *gameState);
extern void initLevel(GameState *game, int level);
extern void initPlayerLevel(Player *player);
extern void gameLoop(GameState *gameState, int levelMAX);
extern void destroyLevel(GameState *gameState);
extern void destroySDL(GameState *gameState);

extern void setStageNum(GameState *game, int stageNum);
extern void setLevelBackground(GameState *game, char* bgImagePath);
extern void loadMap(char *name, GameState *game);
extern void loadGame(GameState *game);
extern void process(GameState *game);
extern int processEvents(GameState *game);

extern void doRender(GameState *game);
extern void doRenderDonut(GameState *game);
extern void doRenderLedges(GameState *game);
extern void doRenderPlayer(GameState *game);

extern void collisionDetect(GameState *game);
extern void updatePlayerPosition(GameState *game);

#endif
