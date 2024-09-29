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