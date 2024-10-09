#include "SuperPellet.h"
int SuperPellet::Super = 0;

SuperPellet::SuperPellet() : Sprite()
{
    set_sprite("../resources/superPellet.png");
    active=0;
    Super=0;
    powerful = false;
}

void SuperPellet::duration()
{
    if(active>0)
    {
        active--;
    }
    else if (active==0&&powerful)
    {
        Super--;
        powerful=false;
    }
}

bool SuperPellet::activePower()
{
    if(Super>0)
    {
        return true;
    }
    else 
        return false;
}

void SuperPellet::activate()
{
    active=450;
    powerful = true;
    Super++;
    set_location(-100,-100);
}