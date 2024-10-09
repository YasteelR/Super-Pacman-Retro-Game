#include "Score.h"
#include <iostream>

using namespace std;

Score::Score()
{
    points=0;
    hScore=false;

    ifstream in;
    in.open("../resources/HighScores.txt");
    if(!in.is_open())
    {
        throw runtime_error("HighScore file not open");
    }

    int High;

    while(in >> High)
    {
        HighScores.emplace_back(High);
    }
}

void Score::storeHighScore()
{
    if(HighScores.size()<5)
    {
        HighScores.emplace_back(points);
        hScore=true;
    }
    if (points > HighScores.back())
    {
        hScore = true;
        HighScores.back() = points;
    }
    sortScores();
    store();
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
            for(int j=HighScores.size()-1; j > i ; j--)
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

void Score::store()
{
    sortScores();
    ofstream out;
    out.open("../resources/HighScores.txt");

    for(int i=0; i<HighScores.size(); i++)
    {
        out << HighScores[i] <<endl;
    }
}

shared_ptr<vector<int>> Score::getHighScores()
{
    auto pointer =make_shared<vector<int>>(HighScores);
    
    return pointer;
}