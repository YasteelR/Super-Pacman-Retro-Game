#ifndef AF83D00B_46A7_46C7_8815_82219216F383
#define AF83D00B_46A7_46C7_8815_82219216F383

#include "BaseObject.h"
#include <raylib-cpp.hpp>

/**
 * @brief Handles rendering of game objects and UI.
 * 
 * The Render class provides methods to draw various objects
 * and manage textures.
 */
class Render : public BaseObject {
public:
    Render() : BaseObject() {};
    
    /**
     * @brief Draws the game map.
     * 
     * @tparam T The type of the objects.
     * @param Object Vector of shared pointers to the objects.
     * @param color The color to draw the map.
     */
    template <typename T>
    void drawMap(vector<shared_ptr<T>> Object, Color color);
    
    /**
     * @brief Draws multiple game objects.
     * 
     * @tparam T The type of the objects.
     * @param Object Vector of shared pointers to the objects.
     */
    template <typename T>
    void drawObjects(vector<shared_ptr<T>> Object);
    
    /**
     * @brief Draws a single game object.
     * 
     * @tparam T The type of the object.
     * @param Object Shared pointer to the object.
     */
    template <typename T>
    void drawObjects(shared_ptr<T> Object);
    
    /**
     * @brief Draws text for game UI.
     * 
     * @tparam T The type of the object.
     * @param Object Vector of objects to display.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    template <typename T>
    void drawText(vector<T>& Object, int x, int y);

private:
    vector<raylib::Texture2D> sprites; ///< Loaded textures for sprites.
    vector<string> image; ///< Filepaths for loaded images.
};

template <typename T>
void Render::drawMap(vector<shared_ptr<T>> Object, Color color) {
    for (int i = 0; i < Object.size(); i++) {
        DrawRectangle(Object[i]->get_x(), Object[i]->get_y(),
                      Object[i]->getWidth(), Object[i]->getHeight(),
                      color);
    }
}

template <typename T>
void Render::drawObjects(vector<shared_ptr<T>> Object) {
    for (int i = 0; i < Object.size(); i++) {
        drawObjects(Object[i]);
    }
}

template <typename T>
void Render::drawText(vector<T>& Object, int x, int y) {   
    if (!Object.empty()) {
        string convert = to_string(Object[0]);
        DrawText(convert.c_str(), x, y, 50, GREEN);
    }
}

template <typename T>
void Render::drawObjects(shared_ptr<T> Object) {
    int pos;
    int xpos = Object->get_x();
    int ypos = Object->get_y();
    bool loaded = false;
    for (int i = 0; i < image.size(); i++) {
        if (Object->getSprite() == image[i]) {
            pos = i;
            loaded = true;
            break;
        }
    }
    if (!loaded) {
        image.emplace_back(Object->getSprite());
        pos = image.size() - 1;
        sprites.emplace_back(LoadTexture(image.back().c_str()));
        DrawTexture(sprites.back(), xpos, ypos, WHITE);
        DrawRectangleLines(xpos, ypos, sprites.back().width, sprites.back().height, (Color){255, 0, 0, 0});
    } else {
        DrawTexture(sprites[pos], xpos, ypos, WHITE);
        DrawRectangleLines(xpos, ypos, sprites[pos].width, sprites[pos].height, (Color){255, 0, 0, 0});
    }
}

#endif /* AF83D00B_46A7_46C7_8815_82219216F383 */
