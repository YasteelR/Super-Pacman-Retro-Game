#include "GameMap.h"

GameMap::GameMap()
{
    //Read in Coordinates of obstacles for the map
    MapFile="game-source-code/GameMap.txt";
    OpenFile();

    if(FileIsOpen())
    {
        ReadData();

        //for(int i=0;i<MapObjects.size(); i++)
        //{
        //   for(int j=0; j<MapObjects[i].size(); j++)
        //    {
        //        cout<<MapObjects[i][j]<<" ";
        //    }
        //    cout<<endl;
        //}

        if(MapObjects.empty())
        {
            throw runtime_error("Map.txt is empty!");
        }
    }
    else    
        throw runtime_error("Map.txt file did not open!");
    CloseFile();
    
}

void GameMap::DrawMap()
{
    DrawBoundary();
    DrawRectangles();
    DrawLines();
}

void GameMap::DrawRectangles()
{
    for(int j=0; j<NumOfRectangles; j++)
    {
        DrawRectangle(MapObjects[j][0], 
                      MapObjects[j][1],
                      MapObjects[j][2],
                      MapObjects[j][3],
                      GREEN);
    }

}

void GameMap::DrawBoundary()
{
    DrawRectangle(0, 0, 50, 900, GREEN);
    DrawRectangle(50, 0, 1550, 50, GREEN);
    DrawRectangle(1550, 50, 50, 850, GREEN);
    DrawRectangle(50, 850, 1500, 50, GREEN);
}

void GameMap::DrawLines()
{
    for(int i=NumOfRectangles; i<MapObjects.size(); i++)
    {
        DrawLine(MapObjects[i][0], 
                      MapObjects[i][1],
                      MapObjects[i][2],
                      MapObjects[i][3],
                      GREEN);
    }
}

void GameMap::SetMapFile(string& FileName)
{
    MapFile=FileName;
    OpenFile();
    if(!FileIsOpen())
    {
        throw runtime_error("File did not open");
    }
    CloseFile();
}


void GameMap::ReadInRectangles()
{
    string HeaderLine;
    InputFile.seekg(0,std::ios::beg);

    while(HeaderLine!="Rectangles" && !InputFile.eof())
    {
        getline(InputFile,HeaderLine);    
    }
