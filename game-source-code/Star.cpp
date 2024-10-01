#include "Star.h"

Star::Star() : Sprite()
{
    set_sprite("../resources/star.png");
    srand(time(0));
    clock=0;
    timer =60;
    
    fruitsFilepath.emplace_back("../resources/banana.png");
    fruitsFilepath.emplace_back("../resources/orange.png");
    fruitsFilepath.emplace_back("../resources/cherry.png");
}

void Star::setUpCompanions(int companions)
{
    createCompanions(companions);
    setCompanionPosition();
}


void Star::createCompanions(int& companions)
{
    for(int i=0; i<companions; i++)
    {
        starFruits.emplace_back(make_shared<Star>());
        starFruits.back()->set_sprite(fruitsFilepath[0]);
    }
}

void Star::setObjects()
{
    clock++;
    if (clock == timer)
    {
        clock=0;
        for (int i = 0; i < starFruits.size(); i++)
        {
            int temp = rand() % 3;
            starFruits[i]->set_sprite(fruitsFilepath[temp]);
        }
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

shared_ptr<vector<shared_ptr<Sprite>>> Star::getCompanions()
{
    auto pointer = make_shared<vector<shared_ptr<Sprite>>>(starFruits);
    return pointer;
}

void Star::setTimer(int duration)
{
    timer=duration;
}