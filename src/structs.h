#ifndef DEF_STRUCTS
#define DEF_STRUCTS
 
#include "defs.h"
 

/**
@struct Player
@brief Player: Structure du joueur contenant ses positions, ses status,compteur de beignes ainsi que les frames.

*/
typedef struct
{
  float x, y, w, h;
  float dx, dy;

  int onLedge;

  int animFrame;
  

  int facingLeft;
  int slowingDown;

  int walking;
  int jumping;

  int playerDonut;


} Player;

typedef struct
{
  float x, y, w, h;
  int ledgeType;
} Ledge;

typedef struct
{
  float x, y, w, h;
  int display;
  int animFrame;
} Donut;

/**
 @fn  int Ledge_getX (Ledge * l);
 @brief game_getLedgeX:Accesseur à une structure legde
 @param [in, out] l pointeur sur ledge
 @return int
 */

int Ledge_getX (Ledge * l);

typedef struct
{
  int stageNum;

	//MAP

	float mapGravity;
	float mapDimX;
	float mapDimY;

  //Players
  Player player;

  //Ledges
  Ledge *ledges;
  int nbLedges;


  //Donut
  Donut *donuts;
  int nbDonuts;


  //Images

  SDL_Texture *sheetTexture;
  SDL_Texture *playerTexture;
  SDL_Texture *donutTexture; 
  SDL_Texture *backgroundTexture;


  int time;

  //Renderer
  SDL_Renderer *renderer;
  SDL_Window *window;                    // Declare une fenetre

} GameState;



#endif
 
