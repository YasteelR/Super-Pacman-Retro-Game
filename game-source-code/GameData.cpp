#include "GameData.h"

void GameData::ReadInWalls(string& FilePath)
{
    FileReader Walls(FilePath);
    Walls.ObjectType("Rectangles");
    Walls.ReadData(WallCoordinates,NumberOfWalls);
}