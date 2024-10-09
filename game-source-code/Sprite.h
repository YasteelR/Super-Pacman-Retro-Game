#ifndef A7554151_12F1_4B26_A7B2_E92F9D6B407A
#define A7554151_12F1_4B26_A7B2_E92F9D6B407A

#include "BaseObject.h"
#include <raylib-cpp.hpp>

/**
 * @brief Represents a sprite with a texture.
 * 
 * The Sprite class manages loading and rendering of textures.
 */
class Sprite : public BaseObject {
public:
    Sprite() : BaseObject() {};
    Sprite(int x, int y) : BaseObject(x, y) {};
    
    /**
     * @brief Sets the sprite texture from a file.
     * 
     * @param filepath The path to the sprite texture file.
     */
    void set_sprite(string filepath);
    
    /**
     * @brief Gets the current sprite file path.
     * 
     * @return string The file path of the sprite.
     */
    string getSprite();
    
    /**
     * @brief Gets the width of the sprite.
     * 
     * @return int The width of the sprite.
     */
    int getWidth();
    
    /**
     * @brief Gets the height of the sprite.
     * 
     * @return int The height of the sprite.
     */
    int getHeight();
    
    /**
     * @brief Gets the bounding box of the sprite.
     * 
     * @return Rectangle The bounding box of the sprite.
     */
    Rectangle getBoundingBox() const;

private:
    raylib::Texture2D sprite; ///< The sprite texture.
    string spriteFilepath; ///< File path for the sprite texture.
};

#endif /* A7554151_12F1_4B26_A7B2_E92F9D6B407A */
