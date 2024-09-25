#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <raylib-cpp.hpp>

using namespace std;


struct Properties{
    bool is_moved;
    bool is_invincible;
    bool is_collided;
    bool is_player;
    bool is_enemy;
    bool is_wall;
    bool is_dead;
    bool is_points;
};



class BaseObject {
    public:
    BaseObject(int x, int y);
    BaseObject();
    Properties get_Properties();
    void set_Properties(Properties new_Properties);
    int get_x();
    int get_y();
    virtual void set_location(int x, int y);
    Rectangle getBoundingBox() const;
    virtual string get_sprite();
    virtual void move_Obj() = 0;
    virtual void undoLastMove() = 0;
    //////////////////////////////////////
    void draw_sprite_object();
    void draw_rectangular_object(vector<int>& objectCoordinates);
    void set_sprite(string sprite_file_location);
    void set_window(shared_ptr<raylib::Window> window);
    void set_moved(bool moved);
    shared_ptr<raylib::Window> get_window();


    protected:
        int current_x;
        int current_y;
    private:
        shared_ptr<raylib::Window> window_;
        string sprite;
        Properties object_Properties;
        raylib::Texture2D spriteObject;

};

#endif 
