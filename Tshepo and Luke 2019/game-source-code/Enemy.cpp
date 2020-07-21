#include "Enemy.h"

Enemy::Enemy()
{
    auto temp = position{};
    auto temp2 = position{};
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 8; col++) {

            temp.x =80.f + col *80.f;
            temp2.x =80.f + col *80.f;
            temp.y = 280.f + row * 30.f;
            temp2.y = 240.f - row * 30.f;
            BottomAliens.push_back(std::make_shared<position>(temp));
            TopAliens.push_back(std::make_shared<position>(temp2));
        }
    }
}
void Enemy::update(const std::vector<std::shared_ptr<position>> aliens, const std::vector<std::shared_ptr<position>> aliens_)
{
    BottomAliens = aliens;
    TopAliens = aliens_;
}
void Enemy::boundaryChecker()
{
    for(auto enemy : BottomAliens) 
    {
        if(enemy->x>= 940.0f && !leftBound) 
        {
            moveDown();
            leftBound=true;
            rightBound=false;
            break;
      } 
        
         if(enemy->x <=0.f && !rightBound)
        {
              moveDown();
             leftBound=false;
             rightBound=true;
             break;
        }
             
    }
    //-------------------------------------------------------------------------------------//
for(auto enemy : TopAliens) 
    {
        if(enemy->x>= 940.0f && !leftBound2) 
        {
            moveUp();
            leftBound2=true;
            rightBound2=false;
            break;
      } 
        
         if(enemy->x <=0.f && !rightBound2)
        {
              moveUp();
             leftBound2=false;
             rightBound2=true;
             break;
        }
        }
}
void Enemy::move()
{     
      boundaryChecker();
      if(!leftBound)
      {
         for(auto enemy : BottomAliens) 
           enemy->x+= speed;
      }
      
     if(!rightBound)
     {
          for(auto enemy : BottomAliens) 
           enemy->x-= speed;
     }
     
      if(!leftBound2)
      {
         for(auto enemy : TopAliens) 
           enemy->x+= speed;
      }
     if(!rightBound2)
     {
          for(auto enemy : TopAliens) 
           enemy->x-= speed;
     }
}

void Enemy::moveDown()
{
    for(auto enemy : BottomAliens) 
        enemy->y+= 10.0f;
}
void Enemy::moveUp()
{
    for(auto enemy : TopAliens) 
      enemy->y-= 10.0f;
}
std::vector<std::shared_ptr<position>> Enemy::BottomAlienPosition()
{
   return BottomAliens;
}
std::vector<std::shared_ptr<position>> Enemy::TopAliensPosition()
{
   return TopAliens;
}
Enemy::~Enemy()
{}
