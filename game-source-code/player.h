#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "BaseObject.h"
#include "raylib-cpp.hpp"
#include <iostream>

using namespace std;

class player : public BaseObject{
public:

    player(int x, int y);
    void move_Obj();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void undoLastMove();
    


private:
    int x_pos;
    int y_pos;  
    string lastMove;
};


#endif 
