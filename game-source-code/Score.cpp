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

void Score::addStarPoints(bool matched1, bool matched2)
{
    if(matched1==true&&matched2==false)
    {
        points=points+2000;
    }
    else if(matched1==true&&matched2==true)
    {
        points=points+5000;
    }
    else 
        points = points +500;
}

string Score::getStringScore()
{
    ScoreString.clear();
    ScoreString="Score: ";
    ScoreString+= to_string(points);

    return ScoreString;
}