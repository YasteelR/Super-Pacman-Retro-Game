#ifndef D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F
#define D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F
#include "raylib-cpp.hpp"
#include <iostream>
#include "Sprite.h"
#include "player.h"

using namespace std;

class Ghost : public Sprite{
public:
    Ghost(int x, int y);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void move_Obj(shared_ptr<player> pacman);
    void undoLastMove();
    void respawn();

private:
    int x_pos;
    int y_pos;  
    string lastMove;
    bool hor;
    bool vert;
    int xSpawn;
    int ySpawn;
};



#endif /* D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F */
