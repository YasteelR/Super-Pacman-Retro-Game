#include "Collisions.h"

bool Collisions::getCollision()
{  
    return get<0>(CollisionObject);
}

int Collisions::getObject()
{
    return get<1>(CollisionObject);
}