#include "prototypes.h"

void initPlayerLevel(Player *player) {
  player->x = 500;
  player->y = 0;
  player->dx = 0;
  player->dy = 0;
  player->w = PLAYER_WIDTH;
  player->h = PLAYER_HEIGTH ;
  player->onLedge = 0;
  player->animFrame = 0;
  player->facingLeft = 0;
  player->slowingDown = 0;
  player->walking = 0;
  player->jumping = 0;
  player->playerDonut = 0;

}

void collisionDetect(GameState *game)
{
  float mw = game->player.w, mh = game->player.h; 
  float mx = game->player.x, my = game->player.y; 


  for(int i = 0; i < game->nbDonuts; i++)
  {
    float gx = game->donuts[i].x, gy = game-> donuts[i].y, gw = game-> donuts[i].w, gh = game-> donuts[i].h;

    if(collide2d(mx,my,gx,gy,mw,mh,gw,gh) && game->donuts[i].display == 1)
    {
      game->donuts[i].display = 0;
      game->player.playerDonut ++;
    }
  }
 

  
  for(int i = 0; i < game->nbLedges; i++)
  {
    float bx = game_getLedgeX(game,i), by = game->ledges[i].y, bw = game->ledges[i].w, bh = game->ledges[i].h; 


   
    
      if(mx+mw/2 > bx && mx+mw/2<bx+bw)
      {
        if(my < by+bh && my > by && game->player.dy < 0)
        {
          game->player.y = by+bh;
          my = by+bh;

          game->player.dy = 0;
          game->player.onLedge = 1;
        }
      }
      if(mx+mw > bx && mx <bx+bw)
      {
        if(my+mh > by && my < by && game->player.dy > 0)
        {
          game->player.y = by-mh;
          my = by-mh;

          game->player.dy = 0;
          game->player.onLedge = 1;
          game->player.jumping = 0;
        }
      }

      if(my+mh > by && my<by+bh)
      {
        if(mx < bx+bw && mx+mw > bx+bw && game->player.dx < 0)
        {
          game->player.x = bx+bw;
          mx = bx+bw;
          game->player.dx = 0;
        }
        else if(mx+mw > bx && mx < bx && game->player.dx > 0)
        {
          game->player.x = bx-mw;
          mx = bx-mw;
          game->player.dx = 0;
        }
      }
    
  }
}


