#include "ObjectBounds.h"


dimensions ObjectBounds::getBounds(IDENTIFIER identifier)
{
    
         if(identifier==LASER_CANNON_1)
        {
            bounds = dimensions { 49.f, 57.f};
            return bounds;
        }
         if(identifier==LASER_CANNON_2)
        {
            bounds = dimensions { 49.f, 57.f};
            return bounds;
        }
        if(identifier==ALIEN_ARMADA)
        {
             bounds = dimensions {28.f, 22.f};
            return bounds;
        }
        if (identifier == BULLET)
        {
         bounds = dimensions {16.f, 16.f};
         return bounds;
        }
        else return bounds;
}

ObjectBounds::~ObjectBounds()
{
}

