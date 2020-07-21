#include "Collision.h"
Collision::Collision()
{
  deltaX = 0.0f;
  deltaY = 0.0f;
  distance =0.0f;
  playerPoints= 0;
     
}
void Collision::Bullet_Aliens(EnemyPositionVector& enemies, BulletPositionVector& bullets)
{
      auto temp = enemies;
      auto temp2 = bullets;
     for(unsigned int i = 0; i < bullets.size(); i++) 
     {
          for(unsigned int j = 0; j < enemies.size(); j++)
              {
             if(checkCollision(bullets[i].x, bullets[i].y, enemies[j]->x, enemies[j]->y,8.f,14.f))
            {
              playerPoints++;
             enemies.erase(enemies.begin() + j);
             bullets.erase(bullets.begin()+i);
             break;
            }
        }
     }
}
bool Collision::checkCollision(float x_,float y_, float x, float y,float radiusOne, float radiusTwo)
{
      deltaX= pow(x_ - x,2);
      deltaY = pow(y_ - y,2);
      distance = sqrt(deltaX+deltaY);
      if(distance < radiusOne+radiusTwo)
      {
          return true;
      }
      else
      {
          return false;
      }
}
bool Collision::Alien_Player(position& playerCoordinates, EnemyPositionVector& enemies)
{
     for(unsigned int i = 0; i < enemies.size(); i++) 
      {
         if(checkCollision(playerCoordinates.x, playerCoordinates.y, enemies[i]->x, enemies[i]->y,12.f,23.5f))
         {
           return true;
         }
      }
      return false;
}
bool Collision::Bullet_Player(position& playerCoordinates, BulletPositionVector& bullets)
{
    for(unsigned int i = 0; i < bullets.size(); i++) 
     {
        if(checkCollision(playerCoordinates.x, playerCoordinates.y, bullets[i].x, bullets[i].y,8.f,24.5f))
           {
               return true;
            }
     }
     return false;
}
void Collision::Bullet_Bullet(BulletPositionVector& bulletsOne,BulletPositionVector& bulletsTwo)
{
      for(unsigned int i = 0; i < bulletsOne.size(); i++)
        {
           for(unsigned int j = 0; j < bulletsTwo.size(); j++)
              {
                if(checkCollision(bulletsOne[i].x, bulletsOne[i].y, bulletsTwo[j].x, bulletsTwo[j].y,8.f,8.f))
                {
                 bulletsOne.erase(bulletsOne.begin() + j);
                 bulletsTwo.erase(bulletsTwo.begin() + i);
                 }
              }
        }
}
int Collision::currentPoints()
{
    return playerPoints;
}
Collision::~Collision()
{
}

