#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <raylib-cpp.hpp>
using namespace std;

/**
 * @brief Represents a base object in the game.
 * 
 * The BaseObject class provides basic functionality for objects 
 * in the game, including position management and window association.
 */
class BaseObject {
public:
    /**
     * @brief Constructor with position parameters.
     * 
     * Initializes the object at specified coordinates.
     * 
     * @param x The initial x-coordinate.
     * @param y The initial y-coordinate.
     */
    BaseObject(int x, int y);
    /**
     * @brief Default constructor.
     * 
     * Initializes the object with default parameters.
     */
    BaseObject();
    /**
     * @brief Gets the x-coordinate of the object.
     * 
     * @return int The current x-coordinate.
     */
    int get_x();
    /**
     * @brief Gets the y-coordinate of the object.
     * 
     * @return int The current y-coordinate.
     */
    int get_y();
    /**
     * @brief Sets the location of the object.
     * 
     * @param x The new x-coordinate.
     * @param y The new y-coordinate.
     */
    void set_location(int x, int y);
    /**
     * @brief Sets the associated window for the object.
     * 
     * @param window The window to associate with this object.
     */
    void set_window(shared_ptr<raylib::Window> window);
    shared_ptr<raylib::Window> get_window(); // Gets the associated window.
protected:
    int current_x; ///< Current x-coordinate of the object.
    int current_y; ///< Current y-coordinate of the object.
private:
    shared_ptr<raylib::Window> window_; ///< Associated window.
};

#endif // BASEOBJECT_H
