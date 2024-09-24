#ifndef D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F
#define D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F
#include "BaseObject.h"
#include "raylib-cpp.hpp"
#include <iostream>

using namespace std;

class Ghost : public BaseObject{
public:
    Ghost(int x, int y);
    void moveGhost();

private:
    int x_pos;
    int y_pos;  
};

#endif /* D090F8A0_C96D_4D4B_A6E4_9D21C536DB0F */