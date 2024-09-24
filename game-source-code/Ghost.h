#ifndef D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F
#define D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F
#include "BaseObject.h"
#include "raylib-cpp.hpp"
#include <iostream>

using namespace std;

class Ghost : public BaseObject{
public:
    Ghost(int x, int y);
    void move_Obj();

private:
    int x_pos;
    int y_pos;  
    string lastMove;
};



#endif /* D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F */
