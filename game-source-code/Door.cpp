#include "Door.h"

Door::Door(int x, int y) : BaseObject(x,y)
{
    set_location(x,y);
}

void Door::move_Obj()
{
    throw runtime_error("Keys cannot move!");
}

void Door::undoLastMove()
{
    throw runtime_error("Keys cannot move!");
}