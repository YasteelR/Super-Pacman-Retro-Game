#include "Wall.h"

// Constructor that initializes the Wall object by calling the base class constructor.
Wall::Wall() : BaseObject() {}

// Returns the width of the wall.
int Wall::getWidth()
{
    return width; // Return the width of the wall.
}

// Returns the height of the wall.
int Wall::getHeight()
{
    return height; // Return the height of the wall.
}

// Sets the height of the wall to a specified value.
void Wall::setHeight(int height_)
{
    height = height_; // Update the height with the provided value.
}

// Sets the width of the wall to a specified value.
void Wall::setWidth(int width_)
{
    width = width_; // Update the width with the provided value.
}