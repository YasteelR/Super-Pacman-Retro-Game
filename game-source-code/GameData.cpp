#include "GameData.h"

GameData& GameData::getData()
{
    return Data;
}

void GameData::ReadInWalls(string FilePath)
{
    FileReader Walls(FilePath);
    Walls.ObjectType("Rectangles");
    Walls.ReadData(WallCoordinates,NumberOfWalls);
}

vector<int>* GameData::getWallCoordinates()
{
    return &WallCoordinates;
}

int* GameData::getNumberOfWalls()
{
    return &NumberOfWalls;
}