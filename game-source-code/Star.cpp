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

    starFruits.emplace_back(make_shared<Sprite>());
    starFruits.back()->set_sprite(fruitsFilepath[0]);

    starFruits.emplace_back(make_shared<Sprite>());
    starFruits.back()->set_sprite(fruitsFilepath[1]);

    starFruits[0]->set_location(801,601);
    starFruits[1]->set_location(701,601);
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

bool Star::CompanionsMatch()
{
    if(starFruits[0]->getSprite()==starFruits[1]->getSprite())
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
    if (starFruits[0]->getSprite() == check && starFruits[1]->getSprite() == check)
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