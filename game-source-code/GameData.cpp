#include "GameData.h"

GameData::GameData(){
    score = 0;
    lives = 3;

}

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