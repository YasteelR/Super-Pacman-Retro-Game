#include "Score.h"

Score::Score()
{
    points=0;
}

void Score::addPoints()
{
    points=points+200;
}

int Score::getScore()
{
    return points;
}