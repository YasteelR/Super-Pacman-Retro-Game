#ifndef EB8834BE_43C1_45B2_A238_AA04B48F971B
#define EB8834BE_43C1_45B2_A238_AA04B48F971B

#include "BaseObject.h"
#include "FileReader.h"

using namespace std;

class GameData
{
    public:
        GameData();
        void ReadInWalls();


    private:
        vector<BaseObject> Object;
        vector<int> WallCoordinates;

};

#endif /* EB8834BE_43C1_45B2_A238_AA04B48F971B */
