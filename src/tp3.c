#include "prototypes.h"

int main(int argc, char *argv[])
{
    GameState gameState;
	initSDL(&gameState);
	gameLoop(&gameState,4);
  	destroySDL(&gameState);

   return 0;
 
}
