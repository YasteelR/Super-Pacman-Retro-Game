#include "Score.h"
#include <iostream>

using namespace std;

Score::Score()
{
    points = 0;
    hScore = false;

    ifstream in;
    in.open("../resources/HighScores.txt");
    if (!in.is_open())
    {
        throw runtime_error("HighScore file not open");
    }

    int High;
    while (in >> High)
    {
        HighScores.emplace_back(High);  // Loads high scores from the file.
    }
}

void Score::storeHighScore()
{
    if (HighScores.size() < 5)
    {
        HighScores.emplace_back(points);
        hScore = true;  // Mark this as a new high score.
    }

    if (points > HighScores.back())
    {
        hScore = true;
        HighScores.back() = points;  // Replace the lowest score if the current score is higher.
    }

    sortScores();
    store();  // Persist the updated high scores.
}

void Score::addPoints()
{
    points += 200;
}

int Score::getScore()
{
    return points;
}

void Score::addStarPoints(bool matched1, bool matched2)
{
    if (matched1 && !matched2)
    {
        points += 2000;
    }
    else if (matched1 && matched2)
    {
        points += 5000;
    }
    else
    {
        points += 500;
    }
}

string Score::getStringScore()
{
    ScoreString = "Score: " + to_string(points);  // Updates score string with current points.
    return ScoreString;
}

bool Score::newHighScore()
{
    return hScore;
}

void Score::sortScores()
{
    // Bubble sort to order high scores in descending order.
    for (int i = 0; i < HighScores.size(); i++)
    {
        for (int j = HighScores.size() - 1; j > i; j--)
        {
            if (HighScores[j] > HighScores[i])
            {
                swap(HighScores[i], HighScores[j]);
            }
        }
    }
}

void Score::store()
{
    ofstream out;
    out.open("../resources/HighScores.txt");

    for (int score : HighScores)
    {
        out << score << endl;  // Write each high score to the file.
    }
}

shared_ptr<vector<int>> Score::getHighScores()
{
    return make_shared<vector<int>>(HighScores);  // Returns a shared pointer to the high scores.
}