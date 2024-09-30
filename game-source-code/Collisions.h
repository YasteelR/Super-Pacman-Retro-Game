#ifndef D15E5CA8_19CC_4569_8BBC_70E46AD52EA7
#define D15E5CA8_19CC_4569_8BBC_70E46AD52EA7

#include <vector>
#include <memory>

using namespace std;

class Collisions
{
    public:
        template <typename T>
        void checkCollisions(vector<shared_ptr<T>> Object);
};

template <typename T>
void Collisions::checkCollisions(vector<shared_ptr<T>> Object)
{
    
}
#endif /* D15E5CA8_19CC_4569_8BBC_70E46AD52EA7 */
