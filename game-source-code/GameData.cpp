#include "GameData.h"

int GameData::getPlayerXpos(){
    return playerX;
}

int GameData::getPlayerYpos(){
    return playerY;
}

void GameData::setPlayerPos(int x, int y){
    playerX = x;
    playerY = y;
}