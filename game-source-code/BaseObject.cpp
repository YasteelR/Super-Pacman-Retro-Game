#include "BaseObject.h"

using namespace std; 

BaseObject::BaseObject(int x_pos, int y_pos){
    current_x = x_pos;
    current_y = y_pos;
    object_Properties = {false,false,false,false,false,false};    
}

Properties BaseObject::get_Properties(){
    return object_Properties;
};

string BaseObject::get_sprite(){
    return sprite;
};

void BaseObject::draw_sprite_object(){
        BeginDrawing();
        ClearBackground(BLUE);
        DrawTexture(spriteObject, get_x(), get_y(), WHITE);
        EndDrawing();
}

void BaseObject::draw_sprite_object_with_map(GameMap& Map){
        //BeginDrawing();
        //ClearBackground(BLUE);
        Map.DrawMap();
        DrawTexture(spriteObject, get_x(), get_y(), WHITE);
        //EndDrawing();
}


void BaseObject::set_Properties(Properties new_Properties){
    object_Properties = new_Properties;
};

void BaseObject::set_sprite(string sprite_file_location){
    sprite = sprite_file_location;
    spriteObject = LoadTexture(sprite_file_location.c_str()); 
};

Rectangle BaseObject::getBoundingBox() const {
        return { current_x, current_y, (float)spriteObject.width, (float)spriteObject.height };
}

void BaseObject::set_location(int x, int y){
    current_x = x;
    current_y = y;
};


int BaseObject::get_x(){
    return current_x;
};

int BaseObject::get_y(){
    return current_y;
};

void BaseObject::set_moved( bool moved){
    object_Properties.is_moved = moved;
};

void BaseObject::set_window(shared_ptr<raylib::Window> window){
    window_ = window;
};

shared_ptr<raylib::Window> BaseObject::get_window(){
    return window_;
};