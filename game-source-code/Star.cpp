#include "Star.h"

Star::Star() : BaseObject()
{
    set_sprite("../resources/star.png");
    srand(time(0));
    clock=0;
    
    fruitsFilepath.emplace_back("../resources/banana.png");
    fruitsFilepath.emplace_back("../resources/orange.png");
    fruitsFilepath.emplace_back("../resources/cherry.png");
}

void Star::setUpCompanions()
{
    createCompanions();
    if(!starFruits.empty())
    {
        starFruits[0]->set_sprite(fruitsFilepath[0]);
        starFruits[1]->set_sprite(fruitsFilepath[2]);
    }
    setCompanionPosition();
}

void Star::createCompanions()
{
    for(int i=0; i<2; i++)
    {
        starFruits.emplace_back(make_shared<Star>());
    }
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
            starFruits[i]->set_sprite(fruitsFilepath[temp]);
        }
    }
}  

void Star::DrawCompanions()
{
    for(int i=0; i<starFruits.size(); i++)
    {
        starFruits[i]->draw_sprite_object();
    }
}

void Star::setCompanionPosition()
{
    if(!starFruits.empty() && starFruits.size()==2)
    {
        starFruits[0]->set_location(get_x()+49,get_y()-1);
        starFruits[1]->set_location(get_x()-51,get_y()-1);
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
    if(starFruits[0]->get_sprite()==starFruits[1]->get_sprite())
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
    if (starFruits[0]->get_sprite() == check && starFruits[1]->get_sprite() == check)
    {
        return true;
    }
    else
        return false;
}

void Star::Destroy()
{
    set_location(-100,-100);
    for(int i=0; i<starFruits.size(); i++)
    {
        starFruits[i]->set_location(-100,-100);
    }
}