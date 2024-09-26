#include "Key.h"

Key::Key() : BaseObject()
{
    set_sprite("../resources/key.png");
}

// void Key::setDoors(Door Object1,Door Object2)
// {
//     doors.emplace_back(make_unique<Door>(Object1));
//     doors.emplace_back(make_unique<Door>(Object2));
// }

void Key::move_Obj()
{
    throw runtime_error("Keys cannot move!");
}

void Key::undoLastMove()
{
    throw runtime_error("Keys cannot move!");
}
