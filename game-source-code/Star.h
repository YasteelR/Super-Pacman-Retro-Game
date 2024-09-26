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

        void move_Obj();
        void undoLastMove();

    private:
        vector<BaseObject> starFruits;
        vector<string> fruitsFilepath;
};

#endif /* BB5257F6_5AD4_4BE3_9A6C_BB94C19F6F37 */
