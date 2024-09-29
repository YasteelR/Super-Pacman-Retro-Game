#include "PowerPellet.h"

PowerPellet::PowerPellet() : BaseObject()
{
    set_sprite("../resources/powerPellet.png");
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
    active=1800;
    set_location(-100,-100);
}