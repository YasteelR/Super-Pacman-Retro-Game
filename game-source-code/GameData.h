#ifndef C9811A90_7114_45EC_9CD0_852731ECEB8D
#define C9811A90_7114_45EC_9CD0_852731ECEB8D
#include "BaseObject.h"
#include "FileReader.h"
#include <memory>

using namespace std;

class GameData{
public:
    GameData();
    
    int getPlayerXpos();
    int getPlayerYpos();
    void setPlayerPos(int x, int y);

private:
    int score;
    int lives;
    int playerX;
    int playerY;
    int highScore;
    


};

#endif /* C9811A90_7114_45EC_9CD0_852731ECEB8D */
