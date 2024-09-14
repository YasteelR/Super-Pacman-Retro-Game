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
