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

string BaseObject::get_sprite(){
    return sprite;
};

void BaseObject::draw_sprite_object(){
        DrawTexture(spriteObject, get_x(), get_y(), WHITE);
        DrawRectangleLines(get_x(),
                           get_y(), 
                           spriteObject.width,
                           spriteObject.height, 
                           (Color){255, 0, 0, 0});
}

void BaseObject::draw_rectangular_object(vector<int>& objectCoordinates){
        for(int i=0; i<objectCoordinates.size()-3; i+4)
        {
            DrawRectangle(objectCoordinates[i], 
                      objectCoordinates[i+1],
                      objectCoordinates[i+2],
                      objectCoordinates[i+3],
                      GREEN);
        }
}


void BaseObject::set_Properties(Properties new_Properties){
    object_Properties = new_Properties;
};

void BaseObject::set_sprite(string sprite_file_location){
    sprite = sprite_file_location;
    spriteObject = LoadTexture(sprite_file_location.c_str()); 
};

Rectangle BaseObject::getBoundingBox() const {

        return { (float)current_x, (float)current_y, (float)spriteObject.width, (float)spriteObject.height };
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