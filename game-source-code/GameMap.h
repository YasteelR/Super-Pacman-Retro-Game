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
        
        //Reads the Map file
        void SetMapFile(string& FileName);
        void OpenFile();
        void OpenFile(string& FileName);//Overload OpenFile to take in a file name
        void CloseFile();
        bool FileIsOpen();
        void ReadData();
        vector<vector<int>> getMapObjects();
        int getNoRectangles();

    private:
        vector<vector<int>> MapObjects;
        string MapFile;
        ifstream InputFile;
        int NumOfRectangles=0;
        int NumOfLines=0;

        void ReadInRectangles();
        void ReadInLines();
        void DrawRectangles();
        void DrawLines();
        void DrawBoundary();
};


#endif /* BEB9148E_1DD3_4978_8B60_98C49B9FE9F8 */
