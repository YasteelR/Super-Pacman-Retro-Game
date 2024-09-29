#ifndef A98570DD_3CC0_4B62_9562_11D1DEE22ADD
#define A98570DD_3CC0_4B62_9562_11D1DEE22ADD

#include <string>
#include <fstream>

using namespace std;

class Score
{
    public:
        Score();
        void addPoints();
        void addStarPoints(bool matched1 , bool matched2);
        int getScore();
        string getStringScore();

    private:
        int points;
        string ScoreString;
};

#endif /* A98570DD_3CC0_4B62_9562_11D1DEE22ADD */
