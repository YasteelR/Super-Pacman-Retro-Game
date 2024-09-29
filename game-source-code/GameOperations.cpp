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

bool GameOperations::checkCollisionPacmanGhost(){
    
    bool collision;
    //check collision with Ghosts
    for (auto i = 1; i < 3; i++ ){
        if (CheckCollisionRecs(movingObjects[0]->getBoundingBox() ,movingObjects[i]->getBoundingBox() )) {
            collision = true;
            gameOver = true;
        }
    }
    return collision;
}

void GameOperations::checkCollisionWall(){
    for (auto& objects : movingObjects ){
        for (auto i = 0; i< WallCoordinates.size() - 3; i= i + 4){
                if (CheckCollisionRecs(returnRect(i, WallCoordinates) ,objects->getBoundingBox() )) {
                    //cout <<"wall collision"<<endl;
                    collision=true;
                    objects->undoLastMove();
            }
            //cout<<"collision Exit"<<endl;
        }
        //cout<<"exit first"<<endl;
    }
    for (auto& objects : movingObjects ){
        for (auto i = 0; i< boundaryCoordinates.size() - 3; i= i + 4){
                if (CheckCollisionRecs(returnRect(i, boundaryCoordinates) ,objects->getBoundingBox() )) {
                    //cout <<"wall collision"<<endl;
                    collision=true;
                    objects->undoLastMove();
            }
            //cout<<"collision Exit"<<endl;
        }
        //cout<<"exit first"<<endl;
    }
    //cout << "Exit both forloop"<<endl;
}

void GameOperations::checkCollisionDoor()
{
    for (auto i = 0; i< doors.size() - 3; i= i + 4){
                if (CheckCollisionRecs(returnRect(i, doors) ,movingObjects[0]->getBoundingBox() )) {
                    //cout <<"wall collision"<<endl;
                    collision=true;
                    movingObjects[0]->undoLastMove();
            }
            //cout<<"collision Exit"<<endl;
        }
}

void GameOperations::checkCollisionKey()
{
    for (auto i = 0; i< keys.size(); i++){
                if (CheckCollisionRecs(keys[i]->getBoundingBox() ,movingObjects[0]->getBoundingBox() )) {
                    //cout <<"wall collision"<<endl;
                    collision=true;
                    keys[i]->destroyDoors(doors);
                    keys[i]->set_location(-100,-100);
            }
            //cout<<"collision Exit"<<endl;
        }
}

void GameOperations::checkCollisionFruit()
{
    for (auto i = 0; i< fruits.size(); i++){
                if (CheckCollisionRecs(fruits[i]->getBoundingBox() ,movingObjects[0]->getBoundingBox() )) {
                    //cout <<"wall collision"<<endl;
                    collision=true;
                    fruits[i]->eatenFruit();
                    fruits[i]->Destroy();
                    points.addPoints();
                    if(fruits[i]->getFruitNum()==0)
                    {
                        gameOver=true;
                    }
            }
            //cout<<"collision Exit"<<endl;
        }
}

void GameOperations::checkCollisionStar()
{
    for (auto i = 0; i< stars.size(); i++){
                if (CheckCollisionRecs(stars[i]->getBoundingBox() ,movingObjects[0]->getBoundingBox() )) {
                    //cout <<"Star collision"<<endl;
                    collision=true;
                    points.addStarPoints(stars[i]->CompanionsMatch(),stars[i]->CompanionsMatchFruit());
                    stars[i]->Destroy();
            }
            //cout<<"collision Exit"<<endl;
        }
}
// void GameOperations::checkCollisionPellets(){
//     for (auto& objects : movingObjects ){
//         for (auto& pellets : pelletList){
//             if (CheckCollisionRecs(wall ,objects->getBoundingBox() )) {
//                 //checl if isdead 
//                 //update score
//             }
//         }
//     }
// }

void GameOperations::draw(){
        BeginDrawing();
        ClearBackground(GREEN);
        for (auto& objects :movingObjects){
            objects->draw_sprite_object();
        }
        for(int i=0; i<boundaryCoordinates.size()-3; i=i+4)
        {
            DrawRectangle(boundaryCoordinates[i], 
                      boundaryCoordinates[i+1],
                      boundaryCoordinates[i+2],
                      boundaryCoordinates[i+3],
                      BLACK);
        }
        for(int i=0; i<WallCoordinates.size()-3; i=i+4)
        {
            DrawRectangle(WallCoordinates[i], 
                      WallCoordinates[i+1],
                      WallCoordinates[i+2],
                      WallCoordinates[i+3],
                      BLACK);
        }
        for(int i=0; i<doors.size()-3; i=i+4)
        {
            DrawRectangle(doors[i], 
                      doors[i+1],
                      doors[i+2],
                      doors[i+3],
                      RED);
        }
        for(int i=0; i<keys.size(); i++)
        {
            keys[i]->draw_sprite_object();
        }
        for(int i=0; i<fruits.size(); i++)
        {
            fruits[i]->draw_sprite_object();
        }
        for(int i=0; i<stars.size(); i++)
        {
            stars[i]->setObjects();
            stars[i]->draw_sprite_object();
            stars[i]->DrawCompanions();
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