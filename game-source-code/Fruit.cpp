#include "Fruit.h"

int Fruit::NumOfFruit=0;

Fruit::Fruit() : Sprite()
{
    NumOfFruit++;
    set_sprite("../resources/banana.png");
}

int Fruit::getFruitNum()
{
    cout<<NumOfFruit<<endl;
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

void Fruit::reset()
{
    NumOfFruit=0;
}