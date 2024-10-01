#include "Sprite.h"

void Sprite::setSprite(string filepath)
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