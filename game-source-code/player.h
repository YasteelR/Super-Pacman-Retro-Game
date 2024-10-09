#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "BaseObject.h"
#include "raylib-cpp.hpp"
#include <iostream>
#include "Move.h"

using namespace std;

class player : public Sprite{
public:
    player();
    player(int x, int y);
    void move_Obj();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void undoLastMove();
    void loseLife();
    bool isDead();
    void immune();
    void setHearts();
    shared_ptr<vector<shared_ptr<Sprite>>> getHearts();
    void setSpeed(int velocity);
    void resetMovers();




private:
    vector<shared_ptr<Sprite>> hearts;
    int lives;
    bool dead;
    string lastMove;
    int vertical;
    int horizontal;
    bool up;
    bool down;
    bool left;
    bool right;
    int speed;
    int newSpeed;
};


#endif 
