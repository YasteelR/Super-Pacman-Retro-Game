#include "Star.h"

Star::Star()
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
    starFruits[0].set_sprite();
    starFruits[1].set_sprite();
    starFruits[2].set_sprite();
}