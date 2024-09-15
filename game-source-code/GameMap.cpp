#include "GameMap.h"

GameMap::GameMap()
{
    //Read in Coordinates of obstacles for the map
    MapFile="game-source-code/GameMap.txt";
    OpenFile();

    if(FileIsOpen())
    {
        ReadInRectangles();
        ReadInLines();

        for(int i=0;i<MapObjects.size(); i++)
        {
            for(int j=0; j<MapObjects[i].size(); j++)
            {
                cout<<MapObjects[i][j]<<" ";
            }
            cout<<endl;
        }

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
}


void GameMap::ReadInRectangles()
{
    string HeaderLine;
    InputFile.seekg(0,std::ios::beg);

    while(HeaderLine!="Rectangles")
    {
        getline(InputFile,HeaderLine);    
    }

    vector<int> temp;
    int coordinates;
    int count=0;
    bool flag=false;
    while(InputFile>>coordinates)
    {
        temp.push_back(coordinates);
        count++;

        if(flag==false)
        {
            flag=true;
        }

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

    if(flag==false)
    {
        throw runtime_error("File contained no coordinates");
    }

    InputFile.clear();
}


void GameMap::ReadInLines()
{
    InputFile.seekg(0,std::ios::beg);
    string HeaderLine;

    while(HeaderLine!="Lines")
    {
        getline(InputFile,HeaderLine);    
    }

    vector<int> temp;
    int coordinates;
    int count=0;
    bool flag=false;
    while(InputFile>>coordinates)
    {
        temp.push_back(coordinates);
        count++;

        if(flag==false)
        {
            flag=true;
        }

        if(count==4)
        {
            count=0;
            MapObjects.push_back(temp);
                
            temp.clear();
            vector<int>().swap(temp);
                
            NumOfLines++;
        }
    }

    if(count!=0)
    {
        count=0;
        MapObjects.push_back(temp);

        temp.clear();
        vector<int>().swap(temp);

        NumOfLines++;
    }

    if(flag==false)
    {
        throw runtime_error("File contained no coordinates");
    }

    InputFile.clear();
}

void GameMap::OpenFile()
{
    InputFile.open(MapFile);
}

void GameMap::CloseFile()
{
    InputFile.close();
}

bool GameMap::FileIsOpen()
{
    if(InputFile.is_open())
    {
        return true;
    }
    else 
        return false;
}