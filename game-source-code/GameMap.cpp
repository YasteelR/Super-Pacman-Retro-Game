#include "GameMap.h"

GameMap::GameMap()
{
    //Read in Coordinates of obstacles for the map
    ifstream MapFile("game-source-code/GameMap.txt");
    int coordinates;

    if(MapFile.is_open())
    {
        vector<int> temp;
        int count=0;
        string Headerline;

        getline(MapFile,Headerline);

        while(MapFile>>coordinates)
        {
            temp.push_back(coordinates);
            count++;
            
            if(count==4)
            {
                count=0;
                MapObjects.push_back(temp);
                
                temp.clear();
                vector<int>().swap(temp);
                
                NumOfRectangles++;
            }
        }

        if(count!=0)
        {
            count=0;
            MapObjects.push_back(temp);

            temp.clear();
            vector<int>().swap(temp);

            NumOfRectangles++;
        }
        getline(MapFile,Headerline);

        while(MapFile>>coordinates)
        {
            
            temp.push_back(coordinates);
            count++;
            if(count==4)
            {
                NumOfLines++;
                count=0;

                MapObjects.push_back(temp);
                
                temp.clear();
                vector<int>().swap(temp);
            }
        }

        if(count!=0)
        {
            NumOfLines++;
            count=0;

            MapObjects.push_back(temp);

            temp.clear();
            vector<int>().swap(temp);
        }
        MapFile.close();
        if(MapObjects.empty()){throw runtime_error("Map.txt is empty!");}
    }
    else if(!MapFile.is_open())   
        throw runtime_error("Map.txt file did not open!");
}


void GameMap::DrawMap()
{
    BeginDrawing();
    ClearBackground(BLACK);

    DrawBoundary();
    for(int j=0; j<MapObjects.size(); j++)
    {
        int size = MapObjects[j].size();
        DrawRectangle(MapObjects[j][size-4], 
                      MapObjects[j][size-3],
                      MapObjects[j][size-2],
                      MapObjects[j][size-1],
                      GREEN);
    }

    EndDrawing();
}

void GameMap::DrawBoundary()
{
    DrawRectangle(0, 0, 50, 900, GREEN);
    DrawRectangle(50, 0, 1550, 50, GREEN);
    DrawRectangle(1550, 50, 50, 850, GREEN);
    DrawRectangle(50, 850, 1500, 50, GREEN);
}


