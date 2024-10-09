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

/**
 * @brief Resets the door's position and size.
 * 
 * Calls `set_location(0,0)` to reset the position and sets width and height to 0,
 * effectively making the door non-existent.
 */
void Door::destroy()
{
    set_location(0, 0);  // Resets the position to the origin.
    width = 0;
    height = 0;
}