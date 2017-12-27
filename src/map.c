#include "prototypes.h"
 
 
Map map;
 
 
void initMaps(void)
{
    map.background = loadImage("../assets/background.png");
}
 
 
SDL_Texture *getBackground(void)
{
    return map.background;
}
 
 
void cleanMaps(void)
{
    if (map.background != NULL)
    {
        SDL_DestroyTexture(map.background);
        map.background = NULL;
    }
 
}
