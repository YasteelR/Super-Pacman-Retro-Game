#ifndef CEB0CD2D_EB3D_4A6A_AF6A_A31B974077F0
#define CEB0CD2D_EB3D_4A6A_AF6A_A31B974077F0

#include "BaseObject.h"

class Ghost : public BaseObject
{
    public:
        Ghost(int Ghosts);
        void HuntPacMan();

    private:
        int NumOfGhosts;
};

#endif /* CEB0CD2D_EB3D_4A6A_AF6A_A31B974077F0 */
