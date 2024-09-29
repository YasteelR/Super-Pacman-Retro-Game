#ifndef B4E447DE_F542_493E_BFDA_9697CE8ED184
#define B4E447DE_F542_493E_BFDA_9697CE8ED184
#ifndef B72A7099_ED11_462A_8938_E27E8FEC105D
#define B72A7099_ED11_462A_8938_E27E8FEC105D
#include "BaseObject.h"
#include "raylib-cpp.hpp"
#include <iostream>

using namespace std;

class PowerPellet : public BaseObject{
public:

    PowerPellet();
    void duration();
    bool activePower();
    void activate();

private:
    int active;
    int PelletNumber;
};


#endif /* B72A7099_ED11_462A_8938_E27E8FEC105D */


#endif /* B4E447DE_F542_493E_BFDA_9697CE8ED184 */
