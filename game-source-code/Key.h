#ifndef C52769D9_9D04_4104_8174_7698B3973915
#define C52769D9_9D04_4104_8174_7698B3973915

#include "BaseObject.h"
#include "Door.h"

using namespace std;

class Key : public BaseObject
{
    public:
        Key();
        void set_location(int x, int y);
        void move_Obj(){throw runtime_error("Keys cannot move!");};
        void undoLastMove();
        virtual void set_location(int x, int y);
        virtual string get_sprite();
        void setDoors(Door& Object1,Door& Object2);

    private:
        vector<unique_ptr<Door>> doors;
};

#endif /* C52769D9_9D04_4104_8174_7698B3973915 */
