#include "Wall.h"


Wall::Wall() : BaseObject(){}

int Wall::getWidth()
{
    return width;
}

int Wall::getHeight()
{
    return height;
}

void Wall::setHeight(int height_)
{
    height=height_;
}

void Wall::setWidth(int width_)
{
    width=width_;
}