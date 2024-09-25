#ifndef DADBC4C0_964C_40F7_98D7_993A0DD45080
#define DADBC4C0_964C_40F7_98D7_993A0DD45080
#include "BaseObject.h"
#include "raylib-cpp.hpp"
#include <iostream>

using namespace std;

class Wall : public BaseObject{
public:

    Wall(int x, int y);

private:
    int x_pos;
    int y_pos;  
};

#endif /* DADBC4C0_964C_40F7_98D7_993A0DD45080 */
