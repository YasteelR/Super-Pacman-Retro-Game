#ifndef D3835E53_B072_4ADE_AC8E_A6F35E290691
#define D3835E53_B072_4ADE_AC8E_A6F35E290691

#include "Sprite.h"
#include "raylib-cpp.hpp"
#include <iostream>

using namespace std;

class SuperPellet : public Sprite{
public:

    SuperPellet();
    void duration();
    bool activePower();
    void activate();

private:
    int active;
    int PelletNumber;
    static int Super;
    bool powerful;
};

#endif /* D3835E53_B072_4ADE_AC8E_A6F35E290691 */
