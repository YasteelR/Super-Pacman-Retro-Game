#include "PowerPellet.h"

PowerPellet::PowerPellet() : BaseObject(){}

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
    active=120;
    set_location(-100,-100);
}