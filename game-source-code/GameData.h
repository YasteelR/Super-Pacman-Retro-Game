#ifndef EB8834BE_43C1_45B2_A238_AA04B48F971B
#define EB8834BE_43C1_45B2_A238_AA04B48F971B

#include "BaseObject.h"

class GameData
{
    public:
        GameData();


    private:
        vector<BaseObject> Object;
        vector<int> WallCoordinates;

};

#endif /* EB8834BE_43C1_45B2_A238_AA04B48F971B */
