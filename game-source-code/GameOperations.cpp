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

void GameOperations::move_objects()
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
            // cout <<"collistion is happening "<<endl;
            // cout <<"player x:"<<movingObjects[0]->get_x()<<"player y:"<<movingObjects[0]->get_y()<<endl;
            // cout <<"ghost x:"<<movingObjects[i]->get_x()<<"ghost y:"<<movingObjects[i]->get_y()<<endl;
            // set player dead
            // update score
        }
    }
    return collision;
}

void GameOperations::checkCollisionWall(){
    for (auto& objects : movingObjects ){
        for (auto i = 0; i< WallCoordinates.size() - 3; i= i + 4){
                if (CheckCollisionRecs(returnRect(i) ,objects->getBoundingBox() )) {
                    //cout <<"wall collision"<<endl;
                    objects->undoLastMove();
            }
            //cout<<"collision Exit"<<endl;
        }
        //cout<<"exit first"<<endl;
    }
    //cout << "Exit both forloop"<<endl;
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
        ClearBackground(BLUE);
        for (auto& objects :movingObjects){
            objects->draw_sprite_object();
        }
        for(int i=0; i<boundaryCoordinates.size()-3; i=i+4)
        {
            DrawRectangle(boundaryCoordinates[i], 
                      boundaryCoordinates[i+1],
                      boundaryCoordinates[i+2],
                      boundaryCoordinates[i+3],
                      GREEN);
        }
        for(int i=0; i<WallCoordinates.size()-3; i=i+4)
        {
            DrawRectangle(WallCoordinates[i], 
                      WallCoordinates[i+1],
                      WallCoordinates[i+2],
                      WallCoordinates[i+3],
                      GREEN);
        }
        EndDrawing();

}

void GameOperations::loadRect(string FilePath){

    FileReader TextFile(FilePath);
    TextFile.ObjectType("Rectangles");
    TextFile.ReadData(WallCoordinates,NumberOfWalls);

    TextFile.ObjectType("Boundaries");
    TextFile.ReadData(boundaryCoordinates,NumberOfBounds);

    TextFile.ObjectType("Keys");
    TextFile.ReadData(keys,NumberOfKeys);

    // TextFile.ObjectType("Pellets");
    // TextFile.ReadData(pellets,NumberOfPellets);

    // for(int i=0; i<pellets.size(); i++)
    // {
    //     cout<<pellets[i]<<" ";
    //     if(i%4==0 && i!=0)
    //     {
    //         cout<<endl;
    //     }
    // }

}
Rectangle GameOperations::returnRect(int& i){
    //cout <<WallCoordinates[i] << "y-"<< WallCoordinates[i +1] << "y-"<< (float)WallCoordinates[i + 2]<< "y-"<< (float)WallCoordinates[i + 3]<<endl;
    return { (float)WallCoordinates[i], (float)WallCoordinates[i +1], (float)WallCoordinates[i + 2], (float)WallCoordinates[i + 3]};
}