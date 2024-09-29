#ifndef B01A566E_8EE6_4DF0_8642_E48F2AD1AC0A
#define B01A566E_8EE6_4DF0_8642_E48F2AD1AC0A

#include "BaseObject.h"

class Move : public BaseObject
{
    public:
        Move(int x, int y);
        virtual void move_Obj() = 0;
        virtual void undoLastMove() = 0;
};

#endif /* B01A566E_8EE6_4DF0_8642_E48F2AD1AC0A */
