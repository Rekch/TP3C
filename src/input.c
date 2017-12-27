#include "prototypes.h"
 
 
void gestionInputs(Input *input)
{
    getInput(input);
}
 
 
void getInput(Input *input)
{
    SDL_Event event;
 
 
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
 
            case SDL_QUIT:
                exit(0);
            break;
 
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(0);
                    break;

                    case SDLK_DELETE:
                        input->erase = 1;
                    break;

                    case SDLK_SPACE:
                        input->jump = 1;
                    break;
 
                    case SDLK_LEFT:
                        input->left = 1;
                    break;
 
                    case SDLK_RIGHT:
                        input->right = 1;
                    break;

                    case (SDLK_RIGHT+SDLK_SPACE):
                        input->jump_right = 1;
                    break;

                    case (SDLK_LEFT+SDLK_SPACE):
                        input->jump_left = 1;
                    break;
 
                    case SDLK_RETURN:
                        input->enter = 1;
                    break;
 
 
                    default:
                    break;
                }
            break;
 
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_DELETE:
                        input->erase = 0;
                    break;
 
                    case SDLK_c:
                        input->jump = 0;
                    break;
 
                    case SDLK_LEFT:
                        input->left = 0;
                    break;
 
                    case SDLK_RIGHT:
                        input->right = 0;
                    break;
 
                    case (SDLK_RIGHT+SDLK_SPACE):
                        input->jump_right = 1;
                    break;

                    case (SDLK_LEFT+SDLK_SPACE):
                        input->jump_left = 1;
                    break;
 
                    case SDLK_RETURN:
                        input->enter = 0;
                    break;
 
                    default:
                    break;
                }
            break;
 
        }
 
    }
}

