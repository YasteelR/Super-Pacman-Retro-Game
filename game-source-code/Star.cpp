#include "Star.h"

Star::Star() : BaseObject()
{
    set_sprite("../resources/star.png");
    starFruits.emplace_back();
    starFruits.emplace_back();
    
    fruitsFilepath.emplace_back("../resources/banana.png");
    fruitsFilepath.emplace_back("../resources/oranges.png");
    fruitsFilepath.emplace_back("../resources/cherry.png");
}

void Star::setObjects()
{
    srand(time(0));
    for(int i=0; i<starFruits.size(); i++)
    {
        int temp = rand()%3;
        starFruits[i].set_sprite(fruitsFilepath[temp]);
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
    for(int i=0; i<starFruits.size(); i++)
    {
        starFruits[i].set_location(get_x(),get_y());
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