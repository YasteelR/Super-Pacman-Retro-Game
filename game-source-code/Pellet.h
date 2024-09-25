#ifndef B72A7099_ED11_462A_8938_E27E8FEC105D
#define B72A7099_ED11_462A_8938_E27E8FEC105D
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


#endif /* B72A7099_ED11_462A_8938_E27E8FEC105D */
