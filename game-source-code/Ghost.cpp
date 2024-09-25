#include "Ghost.h"

Ghost::Ghost(int x, int y, int numOfGhosts) : BaseObject(x,y)
{
    current_x=x;
    current_y=y;
    auto GhostProperties = get_Properties();
    GhostProperties.is_enemy = true;
    set_Properties(GhostProperties);
    NumOfGhosts=numOfGhosts;
}

void Ghost::HuntPacMan()
{
    //Track PacMan and move to him
}