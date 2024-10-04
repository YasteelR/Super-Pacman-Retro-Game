#ifndef BB5257F6_5AD4_4BE3_9A6C_BB94C19F6F37
#define BB5257F6_5AD4_4BE3_9A6C_BB94C19F6F37

#include "Sprite.h"
#include <cstdlib>
#include<ctime>

using namespace std;

class Star : public Sprite
{
    public:
        Star();
        void setObjects();
        void changeImages();
        void DrawCompanions();
        bool CompanionsMatch();
        bool CompanionsMatchFruit();
        void Destroy();
        shared_ptr<vector<shared_ptr<Sprite>>> getCompanions();
        void setTimer(int duration);

    private:
        vector<shared_ptr<Sprite>> starFruits;
        vector<string> fruitsFilepath;
        int clock;
        int timer;
};

#endif /* BB5257F6_5AD4_4BE3_9A6C_BB94C19F6F37 */
