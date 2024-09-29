#ifndef AF83D00B_46A7_46C7_8815_82219216F383
#define AF83D00B_46A7_46C7_8815_82219216F383

#include <vector>
#include <memory>
#include <raylib-cpp.hpp>
#include "BaseObject.h"

using namespace std;

class Render : public BaseObject
{
    public:
        Render() : BaseObject() {};

        template <typename T>
        void drawMap(vector<shared_ptr<T>> Object, Color color);

        template <typename T>
        void drawObjects(vector<shared_ptr<T>> Object);

        template <typename T>
        void drawObjects(shared_ptr<T> Object);

        template <typename T>
        void drawText(vector<T>& Object, int x, int y);
};

template <typename T>
void Render::drawMap(vector<shared_ptr<T>> Object, Color color)
{
    for(int i=0; i<Object.size(); i++)
        {
            DrawRectangle(Object[i]->get_x(), 
                          Object[i]->get_y(),
                          Object[i]->getWidth(),
                          Object[i]->getHeight(),
                          color);
        }
}

template <typename T>
void Render::drawObjects(vector<shared_ptr<T>> Object)
{
    for (int i = 0; i < Object.size(); i++)
    {
        Object[i]->draw_sprite_object();
    }
}

template <typename T>
void Render::drawObjects(shared_ptr<T> Object)
{
    Object->draw_sprite_object();
}

template <typename T>
void Render::drawText(vector<T>& Object, int x, int y)
{
    for(int i=0; i<Object.size(); i++)
    {
        string convert = to_string(Object[i]);
        DrawText(convert.c_str(),x,y,50,GREEN);
        y=y+50;
    }
}
#endif /* AF83D00B_46A7_46C7_8815_82219216F383 */