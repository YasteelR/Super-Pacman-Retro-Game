#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <raylib-cpp.hpp>
#include "GameData.h"

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
    void set_location(int x, int y);
    Rectangle getBoundingBox() const;
    string get_sprite();
    int getSpriteWidth();
    int getSpriteHeight();
    //////////////////////////////////////
    void draw_sprite_object();
    void draw_rectangular_object(vector<int>& objectCoordinates);
    void set_sprite(string sprite_file_location);
    void set_window(shared_ptr<raylib::Window> window);
    void set_moved(bool moved);
    shared_ptr<raylib::Window> get_window();

    void setGameData(shared_ptr<GameData> GameData);
    void updatePlayerGameData();
    int getPlayerX();
    int getPlayerY();


    protected:
        int current_x;
        int current_y;
    private:
        shared_ptr<raylib::Window> window_;
        string sprite;
        Properties object_Properties;
        raylib::Texture2D spriteObject;

        static shared_ptr<GameData> GameInfo;

};


#endif 
