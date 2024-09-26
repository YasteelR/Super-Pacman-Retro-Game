#include "Fruit.h"

int Fruit::NumOfFruit=0;

Fruit::Fruit() : BaseObject()
{
    NumOfFruit++;
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

int Fruit::getFruitNum()
{
    return NumOfFruit;
}

void Fruit::eatenFruit()
{
    NumOfFruit--;
}