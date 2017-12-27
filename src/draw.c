#include "prototypes.h"
 
 
void drawGame(void)
{
 
    drawImage(getBackground(), 0, 0);
 
    SDL_RenderPresent(getrenderer());
 
    SDL_Delay(1);
}
 
SDL_Texture *loadImage(char *name)
{
 
 
    SDL_Surface *loadedImage = NULL;
    SDL_Texture *texture = NULL;
    loadedImage = IMG_Load(name);
 
    if (loadedImage != NULL)
    {
        texture = SDL_CreateTextureFromSurface(getrenderer(), loadedImage);
 
        SDL_FreeSurface(loadedImage);
        loadedImage = NULL;
    }
    else
        printf("L'image n'a pas pu être chargée! SDL_Error : %s\n", SDL_GetError());
 
    return texture;
 
    }
 
 
void drawImage(SDL_Texture *image, int x, int y)
{
 
    SDL_Rect dest;
 
    dest.x = x;
    dest.y = y;
 
    SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(getrenderer(), image, NULL, &dest);
 
}



 
void delay(unsigned int frameLimit)
{
    // Gestion des 60 fps (images/seconde)
    unsigned int ticks = SDL_GetTicks();
 
    if (frameLimit < ticks)
    {
        return;
    }
 
    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }
 
    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}
