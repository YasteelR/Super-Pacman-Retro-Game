#include "BaseObject.h"

using namespace std; 

shared_ptr<GameData> BaseObject::GameInfo = nullptr;


BaseObject::BaseObject()
{
    object_Properties = {false,false,false,false,false,false,false,false};
}

BaseObject::BaseObject(int x_pos, int y_pos){
    current_x = x_pos;
    current_y = y_pos;
    object_Properties = {false,false,false,false,false,false,false,false};    
}

Properties BaseObject::get_Properties(){
    return object_Properties;
};

void BaseObject::set_Properties(Properties new_Properties){
    object_Properties = new_Properties;
};

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

void BaseObject::setGameData(shared_ptr<GameData> GameData){
    GameInfo = GameData;
}

void BaseObject::updatePlayerGameData(){
    GameInfo->setPlayerPos(get_x(),get_y());
}


int BaseObject::getPlayerX(){
    return GameInfo->getPlayerXpos();
}

int BaseObject::getPlayerY(){
    return GameInfo->getPlayerYpos();
}