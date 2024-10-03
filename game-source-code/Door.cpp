#include "Door.h"

Door::Door() : BaseObject(){}

int Door::getWidth()
{
    return width;
}

int Door::getHeight()
{
    return height;
}

void Door::setWidth(int width_)
{
    width=width_;
}

void Door::setHeight(int height_)
{
    height = height_;
}

void Door::destroy()
{
    set_location(0,0);
    width=0;
    height=0;
}