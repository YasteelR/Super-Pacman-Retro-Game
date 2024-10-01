#ifndef A4EC8B3D_2578_488A_8DDC_D51A5CCCD2FC
#define A4EC8B3D_2578_488A_8DDC_D51A5CCCD2FC

#include "Sprite.h"

using namespace std;

class Fruit : public Sprite
{
    public:
        Fruit();
        int getFruitNum();
        static void eatenFruit();
        void Destroy();

    private:
        static int NumOfFruit;
};

#endif /* A4EC8B3D_2578_488A_8DDC_D51A5CCCD2FC */
