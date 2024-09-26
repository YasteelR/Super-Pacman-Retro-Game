#include "Fruit.h"

Fruit::Fruit() : BaseObject()
{
    set_sprite("../resources/key.png");
}

void Fruit::move_Obj()
{
    throw runtime_error("Keys cannot move!");
}

void Fruit::undoLastMove()
{
    throw runtime_error("Keys cannot move!");
}