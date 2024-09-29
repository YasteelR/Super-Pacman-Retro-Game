#include "Fruit.h"

int Fruit::NumOfFruit=0;

Fruit::Fruit() : BaseObject()
{
    NumOfFruit++;
    set_sprite("../resources/banana.png");
}

int Fruit::getFruitNum()
{
    return NumOfFruit;
}

void Fruit::eatenFruit()
{
    NumOfFruit--;
}

void Fruit::Destroy()
{
    set_location(-100,-100);
}