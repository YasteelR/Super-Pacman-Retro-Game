#include "Star.h"

Star::Star() : BaseObject()
{
    set_sprite("../resources/star.png");
    srand(time(0));
    clock=0;
    
    fruitsFilepath.emplace_back("../resources/banana.png");
    fruitsFilepath.emplace_back("../resources/oranges.png");
    fruitsFilepath.emplace_back("../resources/cherry.png");
}

void Star::setUpCompanions()
{
    createCompanions();
    setObjects();
    setCompanionPosition();
}

void Star::createCompanions()
{
    starFruits.emplace_back();
    starFruits.emplace_back();
}

void Star::setObjects()
{
    clock++;
    if (clock == 300)
    {
        clock=0;
        for (int i = 0; i < starFruits.size(); i++)
        {
            int temp = rand() % 3;
            starFruits[i].set_sprite(fruitsFilepath[temp]);
        }
    }
}  

void Star::DrawCompanions()
{
    for(int i=0; i<starFruits.size(); i++)
    {
        starFruits[i].draw_sprite_object();
    }
}

void Star::setCompanionPosition()
{
    if(!starFruits.empty() && starFruits.size()==2)
    {
        starFruits[0].set_location(get_x()+49,get_y()-1);
        starFruits[0].set_location(get_x()-51,get_y()-1);
    }
}

void Star::move_Obj()
{
    throw runtime_error("Keys cannot move!");
}

void Star::undoLastMove()
{
    throw runtime_error("Keys cannot move!");
}
bool Star::CompanionsMatch()
{
    if(starFruits[0].get_sprite()==starFruits[1].get_sprite())
    {
        return true;
    }
    else 
        return false;
}

bool Star::CompanionsMatchFruit()
{
    string check;
    check="../resources/banana.png";

    if(starFruits[0].get_sprite()==check && starFruits[1].get_sprite()==check)
    {
        return true;
    }
    else 
        return false;
}

void Star::Destroy()
{
    current_x=-100;
    current_y=-100;
    for(int i=0; i<starFruits.size(); i++)
    {
        starFruits[i].set_location(-100,-100);
    }
}