#include "Sprite.h"

void Sprite::set_sprite(string filepath)
{
    spriteFilepath=filepath;
    sprite = LoadTexture(filepath.c_str());
}

string Sprite::getSprite()
{
    return spriteFilepath;
}

int Sprite::getWidth()
{
    return sprite.GetWidth();
}
int Sprite::getHeight()
{
    return sprite.GetHeight();
}

Rectangle Sprite::getBoundingBox() const {

        return { (float)current_x, (float)current_y, (float)sprite.width, (float)sprite.height };
}