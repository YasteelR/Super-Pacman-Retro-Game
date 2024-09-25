#ifndef EB8834BE_43C1_45B2_A238_AA04B48F971B
#define EB8834BE_43C1_45B2_A238_AA04B48F971B

#include "BaseObject.h"
#include "FileReader.h"

using namespace std;

class GameData
{
    public:
        //getData() returns a pointer to the single instance of GameData allowing access to it's public member functions
        static GameData& getData();
        void ReadInWalls(string FilePath);
        vector<int>* getWallCoordinates();//Returns a pointer to the vector of wall coordinates (so their positions can be read in)
        int* getNumberOfWalls();
        void setGhosts(); //sets the number of ghosts
        vector<int>* getGhostCoordinates();//Returns a pointer to the ghosts (so their positions can be updated)


    private:
        //The constructor is defined in the private section because we are using the singleton method to prevent
        //multiple instances of the GameData class from being made.
        //GameData();
        //We define the copy and constructor and assignment constructor to delete the object so that no where the 
        //code base can some accidentily create a copy of GameData.
        //GameData(const GameData&) = delete;
        //GameData& operator=(const GameData&) = delete;
        //This creates one instance of GameData that will be used throughout the entire period of the game.
        //static GameData Data;

        vector<BaseObject> Object;
        vector<int> WallCoordinates;
        int NumberOfWalls;
        vector<int> PlayerCoordinates;
        vector<int> GhostCoordinates;
        int NumOfGhosts;
        int score;

};

#endif /* EB8834BE_43C1_45B2_A238_AA04B48F971B */
