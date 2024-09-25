#ifndef EB8834BE_43C1_45B2_A238_AA04B48F971B
#define EB8834BE_43C1_45B2_A238_AA04B48F971B

#include "BaseObject.h"
#include "FileReader.h"

using namespace std;

class GameData
{
    public:
        GameData();
        void ReadInWalls(string FilePath);
        vector<int>* getWallCoordinates();//Returns a pointer to the vector of wall coordinates (so their positions can be read in)
        int* getNumberOfWalls();
        void setGhosts(); //sets the number of ghosts
        vector<int>* getGhostCoordinates();//Returns a pointer to the ghosts (so their positions can be updated)


    private:
        vector<BaseObject> Object;
        vector<int> WallCoordinates;
        int NumberOfWalls;
        vector<int> PlayerCoordinates;
        vector<int> GhostCoordinates;
        int NumOfGhosts;

};

#endif /* EB8834BE_43C1_45B2_A238_AA04B48F971B */
