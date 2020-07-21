#include "Bullet.h"

Bullet::Bullet()
{
 BottomPlayerBulletCoordinates =  position {player_.BottomPlayerPosition().x,player_.BottomPlayerPosition().y}; 
 TopPlayerBulletCoordinates = position {player_.TopPlayerPosition().x, player_.TopPlayerPosition().y};

}
void Bullet::setBulletPosition(IDENTIFIER identifier)
{
    if(identifier == LASER_CANNON_1)
    {
       BottomPlayerBulletCoordinates =  position {player_.BottomPlayerPosition().x,player_.BottomPlayerPosition().y};
    }
    if(identifier== LASER_CANNON_2)
    {
     TopPlayerBulletCoordinates =  position {player_.TopPlayerPosition().x, player_.TopPlayerPosition().y};
    }
    
}
void Bullet::moveBulletUp()
{
      BottomPlayerBulletCoordinates.y -= vertical_speed;
}
void Bullet::moveBulletDown()
{
    TopPlayerBulletCoordinates.y += vertical_speed;
}
 position Bullet::getBulletPosition(IDENTIFIER identifier)
 {
     if(identifier == LASER_CANNON_1)
       {
           return  BottomPlayerBulletCoordinates;
       }
     if(identifier==LASER_CANNON_2)
         {
             return  TopPlayerBulletCoordinates;
         }
        else 
            return position{0.0f, 0.0f};
}
