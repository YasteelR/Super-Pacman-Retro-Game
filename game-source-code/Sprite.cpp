#include "Sprite.h"

// Sets the sprite texture from a given file path.
void Sprite::set_sprite(string filepath)
{
    spriteFilepath = filepath; // Store the file path of the sprite.
    sprite = LoadTexture(filepath.c_str()); // Load the texture from the specified file path.
}

// Returns the file path of the currently set sprite.
string Sprite::getSprite()
{
    return spriteFilepath; // Return the stored sprite file path.
}

// Returns the width of the sprite texture.
int Sprite::getWidth()
{
    return sprite.GetWidth(); // Get and return the width of the sprite texture.
}

// Returns the height of the sprite texture.
int Sprite::getHeight()
{
    return sprite.GetHeight(); // Get and return the height of the sprite texture.
}

// Returns the bounding box of the sprite, which defines its position and dimensions.
Rectangle Sprite::getBoundingBox() const {
    return { (float)current_x, (float)current_y, (float)sprite.width, (float)sprite.height }; // Create and return a Rectangle based on the current position and sprite dimensions.
}

