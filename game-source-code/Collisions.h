#ifndef D15E5CA8_19CC_4569_8BBC_70E46AD52EA7
#define D15E5CA8_19CC_4569_8BBC_70E46AD52EA7

#include <vector>
#include <memory>
#include <raylib-cpp.hpp>

using namespace std;

class Collisions
{
    public:
        Collisions(){};
        template <typename T1, typename T2>
        bool checkCollisions(vector<shared_ptr<T1>> Object, shared_ptr<T2> Player);

        template <typename T>
        Rectangle returnRect(shared_ptr<T> Object);
};

template <typename T1, typename T2>
bool Collisions::checkCollisions(vector<shared_ptr<T1>> Object, shared_ptr<T2> Player)
{
    for(int i=0; i<Object.size(); i++)
    {
        if(CheckCollisionRecs(returnRect(Object[i]), Player->getBoundingBox()))
        {
            return true;
        }
    }
    return false;
}

template <typename T>
Rectangle Collisions::returnRect(shared_ptr<T> Object)
{
    return {(float)Object->get_x(), (float)Object->get_y(), (float)Object->getWidth(), (float)Object->getHeight()};
}

#endif /* D15E5CA8_19CC_4569_8BBC_70E46AD52EA7 */
