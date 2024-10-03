#include "ObjectManager.h"

void ObjectManager::loadObjects(string filepath)
{
    //Create the player and the ghosts and set their positions
    playerPacman = make_shared<player>(player(550,200));
    ghosts.emplace_back(make_shared<Ghost>(750,400));
    ghosts.emplace_back(make_shared<Ghost>(800,400));
    scores = make_shared<Score>();

    ObjectFile.OpenFile(filepath);
    
    //Reading in Objects from text file and constructing them.
    ObjectFile.ObjectType("Rectangles");
    ObjectFile.ReadData4(walls);

    ObjectFile.ObjectType("Boundaries");
    ObjectFile.ReadData4(boundaries);

    ObjectFile.ObjectType("Keys");
    ObjectFile.ReadData2(keys);

    ObjectFile.ObjectType("Doors");
    ObjectFile.ReadData4(doors);

    ObjectFile.ObjectType("Fruits");
    ObjectFile.ReadData2(fruits);

    ObjectFile.ObjectType("Stars");
    ObjectFile.ReadData2(stars);
    for(int i=0; i<stars.size(); i++)
    {
        stars[i]->setUpCompanions(2);
    }

    ObjectFile.ObjectType("Power Pellets");
    ObjectFile.ReadData2(powerpellets);

    ObjectFile.CloseFile();
}