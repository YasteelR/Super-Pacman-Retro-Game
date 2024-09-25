#include "GameOperations.h"

GameOperations::GameOperations(){
    GameData GameInfo;
    loadRect("../resources/GameMap.txt");

    playerPacman = make_shared<player>(player(800,400));
    Ghost1 = make_shared<Ghost>(Ghost(200,200));    
    movingObjects.push_back(playerPacman);
    movingObjects.push_back(Ghost1);
    Ghost1 = make_shared<Ghost>(Ghost(100,100));
    movingObjects.push_back(Ghost1);

    
    // create vector of rectangles

    //create vector of walls



}

void GameOperations::move_objects(GameMap& Map)
{
    for (auto& objects :movingObjects){
        objects->move_Obj();
    }
}   

bool GameOperations::checkCollisionPacmanGhost(){
    
    bool collision;
    //check collision with Ghosts
    for (auto i = 1; i < 3; i++ ){
        if (CheckCollisionRecs(movingObjects[0]->getBoundingBox() ,movingObjects[i]->getBoundingBox() )) {
            collision = true;
            cout <<"collistion is happening "<<endl;
            cout <<"player x:"<<movingObjects[0]->get_x()<<"player y:"<<movingObjects[0]->get_y()<<endl;
            cout <<"ghost x:"<<movingObjects[i]->get_x()<<"ghost y:"<<movingObjects[i]->get_y()<<endl;
            // set player dead
            // update score
        }
    }
    return collision;
}

// void GameOperations::checkCollisionWall(){
//     for (auto& objects : movingObjects ){
//         for (auto& walls : wallList){
//             if (CheckCollisionRecs(wall ,objects->getBoundingBox() )) {
//                 objects->undoLastMove();
//             }
//         }
//     }
// }

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

void GameOperations::drawPlayer(GameMap& Map){
        BeginDrawing();
        ClearBackground(BLUE);
        for (auto& objects :movingObjects){
            objects->draw_sprite_object_with_map(Map);
        }
        EndDrawing();

}

void GameOperations::loadRect(string FilePath){

    FileReader Walls(FilePath);
    Walls.ObjectType("Rectangles");
    Walls.ReadData(WallCoordinates,NumberOfWalls);

    Walls.ObjectType("Boundaries");
    Walls.ReadData(boundaryCoordinates,NumberOfBounds);

}