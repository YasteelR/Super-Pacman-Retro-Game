#ifndef B4E447DE_F542_493E_BFDA_9697CE8ED184
#define B4E447DE_F542_493E_BFDA_9697CE8ED184

#include "Sprite.h"
#include "raylib-cpp.hpp"
#include <iostream>

using namespace std;

class PowerPellet : public Sprite{
public:

    PowerPellet();
    void duration();
    bool activePower();
    void activate();

private:
    int active;
    int PelletNumber;
};

#endif /* B4E447DE_F542_493E_BFDA_9697CE8ED184 */