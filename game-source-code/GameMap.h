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
        void DrawMap();
        void DrawRectangles();
        void DrawBoundary();
        //void DrawGhostSpawn();
    private:
        vector<vector<int>> MapObjects;
        int NumOfRectangles=0;
        int NumOfLines=0;
};


#endif /* BEB9148E_1DD3_4978_8B60_98C49B9FE9F8 */
