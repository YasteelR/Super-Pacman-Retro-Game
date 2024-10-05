#ifndef A7554151_12F1_4B26_A7B2_E92F9D6B407A
#define A7554151_12F1_4B26_A7B2_E92F9D6B407A

#include "BaseObject.h"
#include <raylib-cpp.hpp>

class Sprite : public BaseObject
{
    public:
        Sprite() : BaseObject(){};
        Sprite(int x, int y) : BaseObject(x,y){};
        void set_sprite(string filepath);
        string getSprite();
        int getWidth();
        int getHeight();
        Rectangle getBoundingBox() const;

    
    
    private:
        raylib::Texture2D sprite;
        string spriteFilepath;
};

#endif /* A7554151_12F1_4B26_A7B2_E92F9D6B407A */
