#ifndef C98DA9BF_020E_42CF_BEB5_1BAAFD9D9AEC
#define C98DA9BF_020E_42CF_BEB5_1BAAFD9D9AEC
#include "BaseObject.h"
#include "raylib-cpp.hpp"
#include <iostream>

using namespace std;

class Door : public BaseObject{
public:

    Door();
    int getWidth();
    int getHeight();
    void setWidth(int width_);
    void setHeight(int height_);
    void destroy();

private:
    int width;
    int height;
};

#endif /* C98DA9BF_020E_42CF_BEB5_1BAAFD9D9AEC */
