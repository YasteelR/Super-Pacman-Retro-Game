#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <raylib-cpp.hpp>
#include "GameMap.h"

using namespace std;


struct Properties{
    bool is_moved;
    bool is_invincible;
    bool is_player;
    bool is_enemy;
    bool is_wall;
    bool is_dead;
};

struct lastMove{
    string prevMove;
};

class BaseObject {
    public:
    BaseObject(int x, int y);
    Properties get_Properties();
    void set_Properties(Properties new_Properties);
    int get_x();
    int get_y();
    virtual void set_location(int x, int y);
    virtual string get_sprite();
    //////////////////////////////////////
    void draw_sprite_object();
    void draw_sprite_object_with_map(GameMap& Map);
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

        /////////////////////////////////
        raylib::Texture2D spriteObject;

};

#endif 
