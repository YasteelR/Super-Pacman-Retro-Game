#ifndef D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F
#define D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F
#include "BaseObject.h"
#include "raylib-cpp.hpp"
#include <iostream>
#include "Move.h"

using namespace std;

class Ghost : public Move{
public:
    Ghost(int x, int y);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void move_Obj();
    void undoLastMove();

    void respawn();

private:
    int x_pos;
    int y_pos;  
    string lastMove;
};



#endif /* D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F */
