#ifndef DEF_STRUCTS
#define DEF_STRUCTS
 
#include "defs.h"
 
/* Structures qui seront utilisées pour gérer le jeu */
 
// Structure pour gérer l'input
typedef struct Input
{
 
    int left, right, jump, jump_left, jump_right, enter, erase, pause;
 
} Input;

// Structure pour gérer la map à afficher (à compléter plus tard)
typedef struct Map
{
 
    SDL_Texture *background;
    SDL_Texture *tileSet, *tileSetB;
 
    int tilesetAffiche;
 
    int beginx, beginy;
 
    int startX, startY;
 
    int maxX, maxY;
 
    int tile[MAX_MAP_Y][MAX_MAP_X];
 
    int tile2[MAX_MAP_Y][MAX_MAP_X];
 
    int tile3[MAX_MAP_Y][MAX_MAP_X];
 
    int mapTimer, tileSetNumber;
 
} Map;


 
#endif
