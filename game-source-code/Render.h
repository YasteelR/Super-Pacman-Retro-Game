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

    private:
        vector<raylib::Texture2D> sprites;
        vector<string> image;
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
        drawObjects(Object[i]);
    }
}

template <typename T>
void Render::drawText(vector<T>& Object, int x, int y)
{   
    if(!Object.empty())
    {
        string convert = to_string(Object[0]);
        DrawText(convert.c_str(),x,y,50,GREEN);
    }
}

template <typename T>
void Render::drawObjects(shared_ptr<T> Object)
{
    int pos;
    int xpos = Object->get_x();
    int ypos = Object->get_y();
    bool loaded = false;
    for(int i=0; i<image.size(); i++)
    {
        if(Object->getSprite()==image[i])
        {
            pos=i;
            loaded = true;
            break;
        }
    }
    if(!loaded)
    {
        image.emplace_back(Object->getSprite());
        pos = image.size()-1;
        sprites.emplace_back(LoadTexture(image.back().c_str()));
        DrawTexture(sprites.back(), xpos, ypos, WHITE);
        DrawRectangleLines(xpos,
                           ypos,
                           sprites.back().width,
                           sprites.back().height,
                           (Color){255, 0, 0, 0});
    }
    else 
        DrawTexture(sprites[pos], xpos, ypos, WHITE);
        DrawRectangleLines(xpos,
                           ypos,
                           sprites[pos].width,
                           sprites[pos].height,
                           (Color){255, 0, 0, 0});
}
#endif /* AF83D00B_46A7_46C7_8815_82219216F383 */