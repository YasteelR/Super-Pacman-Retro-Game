#include "Key.h"

Key::Key() : BaseObject()
{
    set_sprite("../resources/key.png");
}

void Key::set_location(int x, int y)
{
    current_x=x;
    current_y=y;
}

void Key::setDoors(Door& Object1,Door& Object2)
{
    doors[0]=make_unique<Door>(Object1);
    doors[1]=make_unique<Door>(Object2);
}

void Key::move_Obj()
{
    throw runtime_error("Keys cannot move!")
}