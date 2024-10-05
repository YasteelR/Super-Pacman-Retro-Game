#include "Sprite.h"

void Sprite::set_sprite(string filepath)
{
    spriteFilepath=filepath;
    sprite = LoadTexture(filepath.c_str());
    rotation = 0;
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

int Sprite::getRotation(){
    return rotation;
}
void Sprite::setRotaion(int orientation){
    rotation = orientation;
}