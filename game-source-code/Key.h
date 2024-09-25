#ifndef C52769D9_9D04_4104_8174_7698B3973915
#define C52769D9_9D04_4104_8174_7698B3973915

#include "BaseObject.h"

using namespace std;

class Key : public BaseObject
{
    public:
        Key(int x, int y);
        void set_location(int x, int y);

    private:
};

#endif /* C52769D9_9D04_4104_8174_7698B3973915 */
