#include "PowerPellet.h"

PowerPellet::PowerPellet() : Sprite()
{
    set_sprite("../resources/powerPellet.png");
    active=0;
}

void PowerPellet::duration()
{
    if(active>0)
    {
        active--;
    }
}

bool PowerPellet::activePower()
{
    if(active>0)
    {
        return true;
    }
    else 
        return false;
}

void PowerPellet::activate()
{
    active=450;
    set_location(-100,-100);
}