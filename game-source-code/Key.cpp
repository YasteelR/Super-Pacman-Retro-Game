#include "Key.h"

Key::Key() : BaseObject()
{
    set_sprite("../resources/key.png");
}

void Key::setDoors(vector<shared_ptr<BaseObject>>& doors, int Position)
{
    doors.push_back(doors[Position]);
    doors.push_back(doors[Position+1]);
}

void Key::move_Obj()
{
    throw runtime_error("Keys cannot move!");
}

void Key::undoLastMove()
{
    throw runtime_error("Keys cannot move!");
}
