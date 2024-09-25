#ifndef EB8834BE_43C1_45B2_A238_AA04B48F971B
#define EB8834BE_43C1_45B2_A238_AA04B48F971B

#include "BaseObject.h"
#include "FileReader.h"
#include <memory>

using namespace std;

class GameData
{
    public:
        static shared_ptr<GameData> getData();
        void ReadInWalls(string FilePath);
        shared_ptr<vector<int>> getWallCoordinates();//Returns a pointer to the vector of wall coordinates (so their positions can be read in)
        shared_ptr<int> getNumberOfWalls();
        int getPlayerXpos();
        int getPlayerYpos();
        void setPlayerCoordinates(int x, int y);
        void setup();


    private:
        //The constructor is defined in the private section because we are using the singleton method to prevent
        //multiple instances of the GameData class from being made.
        GameData(){};
        //We define the copy and constructor and assignment constructor to delete the object so that no where the 
        //code base can some accidentily create a copy of GameData.
        GameData(const GameData&) = delete;
        GameData& operator=(const GameData&) = delete;
        //This creates one instance of GameData that will be used throughout the entire period of the game.
        static shared_ptr<GameData> Data;

        vector<BaseObject> Object;
        vector<int> WallCoordinates;
        int NumberOfWalls;
        int playerXpos;
        int playerYpos;
        vector<int> GhostCoordinates;
        int NumOfGhosts;
        int score;
        int lives;

};

#endif /* EB8834BE_43C1_45B2_A238_AA04B48F971B */
