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
    bool is_player;
    bool is_enemy;
    bool is_wall;
    bool is_dead;
};

class BaseObject {
    public:
    BaseObject(int x, int y);
    Properties get_Properties();
    void set_Properties(Properties new_Properties);
    int get_x();
    int get_y();
    int get_lives();
    int get_points();
    void set_points(int value);
    virtual void set_location(int x, int y);
    virtual string get_sprite();
    void set_sprite(string sprite_file_location);
    //void set_window(shared_ptr<sf::RenderWindow> window);
    void set_moved(bool moved);
    shared_ptr<raylib::window> get_window();


    protected:
        int current_x;
        int current_y;
        int lives;
    private:
        shared_ptr<sf::RenderWindow> window_;
        int point_value;
        string sprite;
        Properties object_Properties;

};

#endif 
