#include <raylib-cpp.hpp>
#include <iostream>

using namespace std;

int main (){
    const int screen_width = 1280;
    const int screen_height = 800;

    raylib::Window window(screen_width, screen_height, "My Pong Game!");
    int x = 1000000;
    while (x!=0)
    {
        cout<< "running"<< endl;
        x--;
    }


    return 0;

}