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

void Sprite::drawSpriteObject(){
        DrawTexture(sprite, get_x(), get_y(), WHITE);
        DrawRectangleLines(get_x(),
                           get_y(), 
                           sprite.width,
                           sprite.height, 
                           (Color){255, 0, 0, 0});
}