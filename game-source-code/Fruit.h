#ifndef A4EC8B3D_2578_488A_8DDC_D51A5CCCD2FC
#define A4EC8B3D_2578_488A_8DDC_D51A5CCCD2FC

#include "BaseObject.h"

using namespace std;

class Fruit : public BaseObject
{
    public:
        Fruit();
        void move_Obj();
        void undoLastMove();
        int getFruitNum();
        static void eatenFruit();

    private:
        static int NumOfFruit;
};

#endif /* A4EC8B3D_2578_488A_8DDC_D51A5CCCD2FC */
