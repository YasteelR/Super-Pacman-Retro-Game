#include "GameData.h"

shared_ptr<GameData> GameData::getData(){
        // If the static Data object is not initialized, initialize it
        if (Data == nullptr) {
            Data = make_shared<GameData>();  // Use make_shared to allocate the object
        }
        return Data;
    }


void GameData::ReadInWalls(string FilePath)
{
    FileReader Walls(FilePath);
    Walls.ObjectType("Rectangles");
    Walls.ReadData(WallCoordinates,NumberOfWalls);
}

shared_ptr<vector<int>> GameData::getWallCoordinates()
{
    return make_shared<vector<int>>(NumberOfWalls);
}

shared_ptr<int> GameData::getNumberOfWalls()
{
    return make_shared<int>(WallCoordinates);
}

void GameData::setPlayerCoordinates(int x, int y){
    playerXpos = x;
    playerYpos = y;
}

int GameData::getPlayerXpos(){
    return playerXpos;
}
int GameData::getPlayerYpos(){
    return playerYpos;
}
void GameData::setup(){
    score = 0;
    lives = 3;
    playerXpos = 800;
    playerYpos = 450;
}