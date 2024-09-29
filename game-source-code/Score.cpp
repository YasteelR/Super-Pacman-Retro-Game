#include "Score.h"

Score::Score()
{
    points=0;
    hScore=false;

    outPut.open("../resources/HighScores");
    if(!outPut.is_open())
    {
        throw runtime_error("HighScore file not open");
    }

    int High;

    while(outPut >> High)
    {
        HighScores.emplace_back(High);
    }
}

void Score::storeHighScore()
{
    if(HighScores.size()<5)
    {
        HighScores.emplace(points);
        hScore=true;
    }
    for(int i=0; i<HighScores.size(); i++)
    {
        if(points>HighScores[i])
        {
            hScore=true;
            HighScores[i]=points;
        }
        break;
    }
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

bool  Score::newHighScore()
{
    return hScore;
}

void Score::sortScores()
{
    int temp;
    for(int i=0; i<HighScores.size(); i++)
    {
            for(int j=HighScores.size()-1; j>i; j++)
            {
                if(HighScores[j]>HighScores[i])
                {
                    temp=HighScores[i];
                    HighScores[i]=HighScores[j];
                    HighScores[j]=temp;
                }
            }
    }
}