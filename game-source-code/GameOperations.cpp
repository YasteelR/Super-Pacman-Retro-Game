#include "GameOperations.h"

GameOperations::GameOperations(){
    shared_ptr<GameData> GameInfo = make_shared<GameData>();
    loadRect("../resources/GameMap.txt");
    collision=false;

    playerPacman = make_shared<player>(player(550,200));
    playerPacman->setGameData(GameInfo);
    Ghosts.emplace_back(make_shared<Ghost>(750,400));
    Ghosts.emplace_back(make_shared<Ghost>(750,450));
    sketch = make_unique<Render>();
    points = make_unique<Score>();
    collide = make_unique<Collisions>();


    gameOver=false;
    // create vector of rectangles

    //create vector of walls



}

void GameOperations::move_objects()
{
    playerPacman->move_Obj();
    for (auto& objects :Ghosts){
        objects->move_Obj();
    }
}   

void GameOperations::checkCollisionPacmanGhost(){
    //check collision with Ghosts
    for (auto i = 0; i < Ghosts.size(); i++ ){
        if (CheckCollisionRecs(playerPacman->getBoundingBox(), Ghosts[i]->getBoundingBox()))
        {
            
            collision = true;
            bool pelletIsActive=false;
            for(int i=0; i<pellets.size(); i++)
            {
                if(pellets[i]->activePower())
                {
                    pelletIsActive=true;
                    break;
                }
            }
            if(!pelletIsActive)
            {
                playerPacman->loseLife();
                playerPacman->set_location(550, 200);
                if (playerPacman->isDead())
                {
                    gameOver = true;
                }
            }
            else 
                Ghosts[i]->respawn();
        }
    }
}


void GameOperations::checkCollisionWall(){
    for (auto &objects : Ghosts)
    {
        for (auto i = 0; i < walls.size(); i++)
        {
            if (CheckCollisionRecs(returnRect(walls[i]), objects->getBoundingBox()))
            {
                collision=true;
                objects->undoLastMove();
            }
            if (CheckCollisionRecs(returnRect(walls[i]), playerPacman->getBoundingBox()))
            {
                collision=true;
                playerPacman->undoLastMove();
            }
        }
    }
    for (auto &objects : Ghosts)
    {
        for (auto i = 0; i < boundaries.size(); i++)
        {
            if (CheckCollisionRecs(returnRect(boundaries[i]), objects->getBoundingBox()))
            {
                collision=true;
                objects->undoLastMove();
            }
            if (CheckCollisionRecs(returnRect(boundaries[i]), playerPacman->getBoundingBox()))
            {
                collision=true;
                playerPacman->undoLastMove();
            }
        }
    }
}

void GameOperations::checkCollisionDoor()
{
    collide->checkCollisions(doors,playerPacman);
    if(collide->getCollision())
    {
        collision = true;
        playerPacman->undoLastMove();
    }
    collide->resetCollision();
}

void GameOperations::checkCollisionKey()
{
    collide->checkCollisions(keys,playerPacman);
    if (collide->getCollision())
    {
        collision = true;
        keys[collide->getObject()]->destroyDoors(doors);
        keys[collide->getObject()]->set_location(-100, -100);
    }
    collide->resetCollision();
}

void GameOperations::checkCollisionFruit()
{
    for (auto i = 0; i < fruits.size(); i++)
    {
        if (CheckCollisionRecs(fruits[i]->getBoundingBox(), playerPacman->getBoundingBox()))
        {
            collision = true;
            fruits[i]->eatenFruit();
            fruits[i]->Destroy();
            points->addPoints();
            if (fruits[i]->getFruitNum() == 0)
            {
                gameOver = true;
            }
        }
    }
}

void GameOperations::checkCollisionStar()
{
    for (auto i = 0; i < stars.size(); i++)
    {
        if (CheckCollisionRecs(stars[i]->getBoundingBox(), playerPacman->getBoundingBox()))
        {
            collision = true;
            points->addStarPoints(stars[i]->CompanionsMatch(), stars[i]->CompanionsMatchFruit());
            stars[i]->Destroy();
        }
    }
}

void GameOperations::checkCollisionPellets()
{
    for (auto i = 0; i < pellets.size(); i++)
    {
        pellets[i]->duration();
        if (CheckCollisionRecs(pellets[i]->getBoundingBox(), playerPacman->getBoundingBox()))
        {
            pellets[i]->activate();
        }
    }
}

void GameOperations::draw(){
        BeginDrawing();
        ClearBackground(GREEN);
        sketch->drawObjects(playerPacman);
        sketch->drawObjects(Ghosts);
        sketch->drawMap(walls,BLACK);
        sketch->drawMap(boundaries,BLACK);
        sketch->drawMap(doors,RED);
        string hhh="Lives: ";
        DrawText(hhh.c_str(),50, 800, 50, GREEN);
        sketch->drawObjects(*(playerPacman->getHearts()));
        sketch->drawObjects1(keys);
        sketch->drawObjects(fruits);
        sketch->drawObjects(pellets);
        for(int i=0; i<stars.size(); i++)
        {
            stars[i]->setObjects();
            sketch->drawObjects(stars);
            sketch->drawObjects(*(stars[i]->getCompanions()));
        }
        DrawText(points->getStringScore().c_str(),600, 50, 50, GREEN);

        string sss="Current High Score: ";
        DrawText(sss.c_str(), 400, 800, 50 ,GREEN);
        sketch->drawText(*(points->getHighScores()), 1450, 50);
        EndDrawing();
}

void GameOperations::loadRect(string FilePath){

    FileReader TextFile(FilePath);
    TextFile.ObjectType("Rectangles");
    TextFile.ReadData4(walls);

    TextFile.ObjectType("Boundaries");
    TextFile.ReadData4(boundaries);

    TextFile.ObjectType("Keys");
    TextFile.ReadData2(keys);

    TextFile.ObjectType("Doors");
    TextFile.ReadData4(doors);

    TextFile.ObjectType("Fruits");
    TextFile.ReadData2(fruits);

    TextFile.ObjectType("Stars");
    TextFile.ReadData2(stars);
    for(int i=0; i<stars.size(); i++)
    {
        stars[i]->setUpCompanions(2);
    }

    TextFile.ObjectType("Power Pellets");
    TextFile.ReadData2(pellets);
    for(int i=0; i<pellets.size(); i++)
    {
        
    }
}

bool GameOperations::getGameOver(){
    return gameOver;
}

bool GameOperations::getCollision()
{
    return collision;
}

void GameOperations::resetCollision()
{
    collision=false;
}