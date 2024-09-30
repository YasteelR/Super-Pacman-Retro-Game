#ifndef A98570DD_3CC0_4B62_9562_11D1DEE22ADD
#define A98570DD_3CC0_4B62_9562_11D1DEE22ADD

#include <string>
#include <fstream>
#include <memory>
#include <vector>

using namespace std;

class Score
{
    public:
        Score();
        void addPoints();
        void addStarPoints(bool matched1 , bool matched2);
        int getScore();
        string getStringScore();
        void storeHighScore();
        bool newHighScore();
        void sortScores();
        void store();
        shared_ptr<vector<int>> getHighScores();
        
    private:
        int points;
        string ScoreString;
        vector<int> HighScores;
        bool hScore;
};

#endif /* A98570DD_3CC0_4B62_9562_11D1DEE22ADD */
