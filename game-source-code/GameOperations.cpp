#include "GameOperations.h"

GameOperations::GameOperations(){
    loadRect("../resources/GameMap.txt");
    collision=false;

    Ghosts.emplace_back(make_shared<Ghost>(750,400));
    Ghosts.emplace_back(make_shared<Ghost>(800,400));
    sketch = make_unique<Render>();
    points = make_unique<Score>();
    collide = make_unique<Collisions>();
    freeze = 180;


    gameOver=false;
    // create vector of rectangles

    //create vector of walls

}

void GameOperations::move_objects()
{
    if(freeze==0)
    {
        playerPacman->move_Obj();
        for (auto& objects :Ghosts){
            objects->move_Obj(playerPacman);
        }
    }
    else 
        freeze--;
}   

void GameOperations::handleCollisions()
{
    handleCollisionPacmanGhost();
    handleCollisionWall();
    handleCollisionDoor();
    handleCollisionFruit();
    handleCollisionKey();
    handleCollisionPellets();
    handleCollisionStar();
    handleCollisionSPellets();
}

void GameOperations::handleCollisionPacmanGhost(){
    //check collision with Ghosts
    collide->checkCollisions(Ghosts, playerPacman);
    if (collide->getCollision())
    {
        collision = true;
        bool pelletIsActive = false;
        for (int i = 0; i < pellets.size(); i++)
        {
            if (pellets[i]->activePower())
            {
                pelletIsActive = true;
                break;
            }
        }
        if (!pelletIsActive && !spellets[0]->activePower())
        {
            freeze=180;
            playerPacman->resetMovers();
            playerPacman->loseLife();
            playerPacman->set_location(550, 200);
            for(int i=0; i<Ghosts.size(); i++)
            {
                Ghosts[i]->respawn();
            }
            if (playerPacman->isDead())
            {
                gameOver = true;
                points->storeHighScore();
            }
        }
        else if(pelletIsActive)
        {
            Ghosts[collide->getObject()]->respawn();
        }
    }
    collide->resetCollision();
}


void GameOperations::handleCollisionWall(){
    collide->checkCollisions(walls,playerPacman);
    if(collide->getCollision())
    {
        collision=true;
        playerPacman->undoLastMove();
    }
    collide->resetCollision();

    for(int i=0; i<Ghosts.size(); i++)
    {
        collide->checkCollisions(walls,Ghosts[i]);
        if(collide->getCollision())
        {
            collision=true;
            Ghosts[i]->undoLastMove();
        }
        collide->resetCollision();
    }
}

void GameOperations::handleCollisionDoor()
{
    collide->checkCollisions(doors,playerPacman);

    if(collide->getCollision()&&!spellets[0]->activePower())
    {
        collision = true;
        playerPacman->undoLastMove();
    }
    else if(collide->getCollision()&&spellets[0]->activePower())
    {
        collision = true;
        doors[collide->getObject()]->destroy();
    }
    collide->resetCollision();
}

void GameOperations::handleCollisionKey()
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

void GameOperations::handleCollisionFruit()
{
    collide->checkCollisions(fruits,playerPacman);
    if(collide->getCollision())
    {
        collision = true;
        fruits[collide->getObject()]->eatenFruit();
        fruits[collide->getObject()]->Destroy();
        points->addPoints();
        if (fruits[collide->getObject()]->getFruitNum() == 0)
        {
            gameOver = true;
            points->storeHighScore();
        }
    }
    collide->resetCollision();
}

void GameOperations::handleCollisionStar()
{
    collide->checkCollisions(stars,playerPacman);
    if (collide->getCollision())
    {
        collision = true;
        points->addStarPoints(stars[collide->getObject()]->CompanionsMatch(), stars[collide->getObject()]->CompanionsMatchFruit());
        stars[collide->getObject()]->Destroy();
    }
    collide->resetCollision();
}

void GameOperations::handleCollisionPellets()
{
    for(int i=0; i<pellets.size(); i++)
    {
        pellets[i]->duration();
    }
    collide->checkCollisions(pellets,playerPacman);
    if (collide->getCollision())
    {
        pellets[collide->getObject()]->activate();
    }
    collide->resetCollision();
}

void GameOperations::handleCollisionSPellets()
{
    bool SuperMode=false;
    for(int i=0; i<spellets.size(); i++)
    {
        spellets[i]->duration();
    }
    if(!spellets[0]->activePower())
    {
        playerPacman->setSpeed(2);
    }
    collide->checkCollisions(spellets,playerPacman);
    if (collide->getCollision())
    {
        spellets[collide->getObject()]->activate();
        playerPacman ->setSpeed(5);
    }
    collide->resetCollision();
}

void GameOperations::draw(){
        BeginDrawing();
        ClearBackground(GREEN);
        sketch->drawObjects(playerPacman);
        sketch->drawObjects(Ghosts);
        sketch->drawMap(walls,BLACK);
        sketch->drawMap(doors,RED);
        string hhh="Lives: ";
        DrawText(hhh.c_str(),50, 800, 50, GREEN);
        sketch->drawObjects(*(playerPacman->getHearts()));
        sketch->drawObjects(keys);
        sketch->drawObjects(fruits);
        sketch->drawObjects(pellets);
        sketch->drawObjects(spellets);
        for(int i=0; i<stars.size(); i++)
        {
            stars[i]->setObjects();
            sketch->drawObjects(stars);
            sketch->drawObjects(*(stars[i]->getCompanions()));
        }
        DrawText(points->getStringScore().c_str(),600, 50, 50, GREEN);

        string sss="Current High Score: ";
        DrawText(sss.c_str(), 400, 800, 50 ,GREEN);
        sketch->drawText(*(points->getHighScores()), 1000, 800);
         
        if(freeze%60==0)
        {
            input = to_string(freeze/60);
        }
        if(freeze>0)
        {
            DrawText(input.c_str(), 600, 300, 200, YELLOW);
        }
        EndDrawing();
}

void GameOperations::loadRect(string FilePath){

    FileReader TextFile(FilePath);
    
    TextFile.ObjectType("Player");
    TextFile.ReadData2(playerPacman);

    TextFile.ObjectType("Walls");
    TextFile.ReadData4(walls);

    TextFile.ObjectType("Keys");
    TextFile.ReadData2(keys);

    TextFile.ObjectType("Doors");
    TextFile.ReadData4(doors);

    TextFile.ObjectType("Fruits");
    TextFile.ReadData2(fruits);

    TextFile.ObjectType("Stars");
    TextFile.ReadData2(stars);

    TextFile.ObjectType("Power Pellets");
    TextFile.ReadData2(pellets);

    TextFile.ObjectType("Super Pellets");
    TextFile.ReadData2(spellets);
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