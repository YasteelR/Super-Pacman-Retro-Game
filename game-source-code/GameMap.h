#ifndef BEB9148E_1DD3_4978_8B60_98C49B9FE9F8
#define BEB9148E_1DD3_4978_8B60_98C49B9FE9F8

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <raylib-cpp.hpp>

using namespace std;

class GameMap
{
    public:
        GameMap();

        //Draws the Map
        void DrawMap();
        void DrawRectangles();
        void DrawLines();
        void DrawBoundary();
        
        //Reads the Map file
        void SetMapFile(string& FileName);
        void ReadInRectangles();
        void ReadInlines();

    private:
        vector<vector<int>> MapObjects;
        string MapFile;
        int NumOfRectangles=0;
        int NumOfLines=0;
};


#endif /* BEB9148E_1DD3_4978_8B60_98C49B9FE9F8 */
