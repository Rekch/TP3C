#include "prototypes.h"
 
 
Input input;
 
 
int main(int argc, char *argv[])
{
    unsigned int frameLimit = SDL_GetTicks() + 16;
    int go;
 
    init("TP3-Le ramasseur de donuts");
 
    loadGame();

    atexit(cleanup);
 
    go = 1;
 
    while (go == 1)
    {
        gestionInputs(&input);
 
        drawGame();
 
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }
 
    exit(0);
 
}
