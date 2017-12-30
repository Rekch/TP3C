#ifndef PROTOTYPES
#define PROTOTYPES
 
#include "structs.h"

extern void initMenu(GameState *game,int choice);
/**
 @fn int collide2d(float x1, float y1, float x2, float y2, float wt1, float ht1, float wt2, float ht2)
 @brief collide2d: "fonction de collision en entre le joueur les ledges" 
 @param [in] x1 y1 x2 y2 wt1 ht1 wt2 ht2 de type float 
 @return int
 */
extern int collide2d(float x1, float y1, float x2, float y2, float wt1, float ht1, float wt2, float ht2);
 
/**
 @fn int** createArray(int m, int n)
 @brief createArray: "création d'un tableau 2D" 
 @param [in] n m de type int
 @return int**
 */
extern int** createArray(int m, int n);
/**
 @fn void destroyArray(int** arr)
 @brief doRender: "testament pour la destruction du tableau 2D " 
 @param [in, out] arr double pointeur(tableau 2D)
 @return void
 */
extern void destroyArray(int** arr); 
extern int Ledge_getX (Ledge * l);

extern int game_getLedgeX(GameState *game, int i);
extern void SetStageNum(GameState *game, int stageNum);
extern void initLevel(GameState *game, int level);
extern void loadMap(char *name, GameState *game);
extern void loadGame(GameState *game);
extern void process(GameState *game);
extern void collisionDetect(GameState *game);
extern void updateManPosition(GameState *game);
extern void setLevelBackground(GameState *game, char* bgImagePath);
extern int processEvents(GameState *game);
extern void doRender(GameState *game);
extern void initSDL(GameState *gameState);
extern void gameLoop(GameState *gameState, int levelMAX);
extern void destroyLevel(GameState *gameState);
extern void destroySDL(GameState *gameState);
extern void doRenderDonut(GameState *game);
extern void doRenderLedges(GameState *game);
extern void doRenderMan(GameState *game);
extern void initPlayerLevel(Player *player);

#endif
