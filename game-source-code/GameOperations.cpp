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
    for (auto i = 0; i < doors.size(); i++)
    {
        if (CheckCollisionRecs(returnRect(doors[i]), playerPacman->getBoundingBox()))
        {
            collision = true;
            playerPacman->undoLastMove();
        }
    }
}

void GameOperations::checkCollisionKey()
{
    for (auto i = 0; i < keys.size(); i++)
    {
        if (CheckCollisionRecs(keys[i]->getBoundingBox(), playerPacman->getBoundingBox()))
        {
            collision = true;
            keys[i]->destroyDoors(doors);
            keys[i]->set_location(-100, -100);
        }
    }
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
            points.addPoints();
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
            points.addStarPoints(stars[i]->CompanionsMatch(), stars[i]->CompanionsMatchFruit());
            stars[i]->Destroy();
        }
    }
}

void GameOperations::checkCollisionPellets()
{
    for (auto i = 0; i < pellets.size(); i++)
    {
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
        DrawText(hhh.c_str(),600, 800, 50, GREEN);
        sketch->drawObjects(*(playerPacman->getHearts()));
        sketch->drawObjects(keys);
        sketch->drawObjects(fruits);
        for(int i=0; i<stars.size(); i++)
        {
            stars[i]->setObjects();
            sketch->drawObjects(stars);
            sketch->drawObjects(*(stars[i]->getCompanions()));
        }
        DrawText(points.getStringScore().c_str(),600, 50, 50, GREEN);
        EndDrawing();

}

void GameOperations::loadRect(string FilePath){

    FileReader TextFile(FilePath);
    TextFile.ObjectType("Rectangles");
    TextFile.ReadData(WallCoordinates,NumberOfWalls);

    TextFile.ObjectType("Boundaries");
    TextFile.ReadData(boundaryCoordinates,NumberOfBounds);

    TextFile.ObjectType("Keys");
    TextFile.ReadDataObject(keys,NumberOfKeys);

    TextFile.ObjectType("Doors");
    TextFile.ReadData(doors,NumberOfDoors);

    TextFile.ObjectType("Fruits");
    TextFile.ReadDataObject(fruits,NumberOfFruits);

    TextFile.ObjectType("Stars");
    TextFile.ReadDataObject(stars,NumberOfStars);
    stars[0]->setUpCompanions();
    // TextFile.ObjectType("Pellets");
    // TextFile.ReadData(pellets,NumberOfPellets);

    // for(int i=0; i<keys.size(); i++)
    // {
    //     cout<<keys[i]->get_x()<<" "<<keys[i]->get_y()<<" "<<endl;
    // }

}
Rectangle GameOperations::returnRect(int& i, vector<int>& vector){
    //cout <<WallCoordinates[i] << "y-"<< WallCoordinates[i +1] << "y-"<< (float)WallCoordinates[i + 2]<< "y-"<< (float)WallCoordinates[i + 3]<<endl;
    return { (float)vector[i], (float)vector[i +1], (float)vector[i + 2], (float)vector[i + 3]};
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