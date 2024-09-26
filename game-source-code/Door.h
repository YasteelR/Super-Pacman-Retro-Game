#ifndef C98DA9BF_020E_42CF_BEB5_1BAAFD9D9AEC
#define C98DA9BF_020E_42CF_BEB5_1BAAFD9D9AEC
#include "BaseObject.h"
#include "raylib-cpp.hpp"
#include <iostream>

using namespace std;

class Door : public BaseObject{
public:

    Door(int x, int y);
    void move_Obj();
    void undoLastMove();

private:
    
};

#endif /* C98DA9BF_020E_42CF_BEB5_1BAAFD9D9AEC */
