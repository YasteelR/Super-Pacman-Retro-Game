#include "BaseObject.h"

using namespace std;

BaseObject::BaseObject(){}

BaseObject::BaseObject(int x_pos, int y_pos){
    current_x = x_pos;
    current_y = y_pos;   
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

void BaseObject::set_window(shared_ptr<raylib::Window> window){
    window_ = window;
};

shared_ptr<raylib::Window> BaseObject::get_window(){
    return window_;
};