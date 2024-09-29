#ifndef BB5257F6_5AD4_4BE3_9A6C_BB94C19F6F37
#define BB5257F6_5AD4_4BE3_9A6C_BB94C19F6F37

#include "BaseObject.h"
#include <cstdlib>
#include<ctime>

using namespace std;

class Star : public BaseObject
{
    public:
        Star();
        void setObjects();
        void changeImages();
        void DrawCompanions();
        void setCompanionPosition();
        void createCompanions(int& companions);
        void setUpCompanions(int companions);
        bool CompanionsMatch();
        bool CompanionsMatchFruit();
        void Destroy();
        shared_ptr<vector<shared_ptr<BaseObject>>> getCompanions();
        void setTimer(int duration);

    private:
        vector<shared_ptr<BaseObject>> starFruits;
        vector<string> fruitsFilepath;
        int clock;
        int timer;
};

#endif /* BB5257F6_5AD4_4BE3_9A6C_BB94C19F6F37 */
