#ifndef A98570DD_3CC0_4B62_9562_11D1DEE22ADD
#define A98570DD_3CC0_4B62_9562_11D1DEE22ADD

class Score
{
    public:
        Score();
        void addPoints();
        void addStarPoints(bool matched1 , bool matched2);
        int getScore();

    private:
        int points;
};

#endif /* A98570DD_3CC0_4B62_9562_11D1DEE22ADD */
