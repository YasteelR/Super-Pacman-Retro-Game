#include "Sprite.h"

void Sprite::setSprite(string filepath)
{
    spriteFilepath=filepath;
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