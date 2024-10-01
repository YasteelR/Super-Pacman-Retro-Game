#ifndef A7554151_12F1_4B26_A7B2_E92F9D6B407A
#define A7554151_12F1_4B26_A7B2_E92F9D6B407A

#include "BaseObject.h"

class Sprite : public BaseObject
{
    public:
        void setSprite(string filepath);
        string getSprite();
        int getWidth();
        int getHeight();
    
    private:
        raylib::Texture2D sprite;
        string spriteFilepath;
};

#endif /* A7554151_12F1_4B26_A7B2_E92F9D6B407A */
