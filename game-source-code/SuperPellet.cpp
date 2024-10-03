#include "SuperPellet.h"

SuperPellet::SuperPellet() : Sprite()
{
    set_sprite("../resources/superPellet.png");
    active=0;
}

void SuperPellet::duration()
{
    if(active>0)
    {
        active--;
    }
}

bool SuperPellet::activePower()
{
    if(active>0)
    {
        return true;
    }
    else 
        return false;
}

void SuperPellet::activate()
{
    active=450;
    set_location(-100,-100);
}