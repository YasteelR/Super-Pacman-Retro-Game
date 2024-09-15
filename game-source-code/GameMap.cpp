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

        for(int i=0;i<MapObjects.size(); i++)
        {
            for(int j=0; j<MapObjects[i].size(); j++)
            {
                cout<<MapObjects[i][j]<<" ";
            }
            cout<<endl;
        }

        MapFile.clear();
        MapFile.seekg(MapObjects.size()*4,std::ios::beg);
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
    ifstream(MapFile);
    if(!MapFile)
    {
        throw runtime_error("File did not open");
    }
}


void GameMap::ReadInRectangles()
{
    ifstream ifile(MapFile);
    string HeaderLine;

    while(HeaderLine!="Rectangles")
    {
        getline(ifile,HeaderLine);    
    }

    vector<int> temp;
    int coordinates;
    int count=0;
    bool flag=false;
    while(ifile>>coordinates)
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

    ifile.clear();
    ifile.close();
}


void GameMap::ReadInLines()
{
    ifstream ifile(MapFile);
    string HeaderLine;

    while(HeaderLine!="Lines")
    {
        getline(ifile,HeaderLine);    
    }

    vector<int> temp;
    int coordinates;
    int count=0;
    bool flag=false;
    while(ifile>>coordinates)
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

    ifile.clear();
    ifile.close();
}

