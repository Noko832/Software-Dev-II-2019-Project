#include "Collision.h"
#include "Bullet.h"
#include <iostream>

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

//////----------------Bullet Player Collision Test-------------------------/////
TEST_CASE("Check That No Collision Is Detected Between Bottom Player And Top Bullet From Top Player")
{ 
    //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto bullet=Bullet{};
    auto topBulletPos=position{};
    auto bottomPlayerPos=position{};
    bottomPlayerPos.x = 480.0f-23.8f;  //Bottom Players Initial X-Position
    bottomPlayerPos.y = 540.0f-57.f;   //Bottom Players Initial Y-Position
    BulletPositionVector bulVecPos; 
    //Set bullet coordinates to that of the top players initial coordinates(middle of screen)
    bullet.setBulletPosition(LASER_CANNON_2); 
    topBulletPos=bullet.getBulletPosition(LASER_CANNON_2);
    bulVecPos.push_back(topBulletPos);
    CHECK_FALSE(collision.Bullet_Player(bottomPlayerPos,bulVecPos));
}

TEST_CASE("Check That There Is Collision Is Detected Between Bottom Player And Top Bullet From Top Player In The Middle Of The Screen")
{ 
    //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto bullet=Bullet{};
    auto topBulletPos=position{};
    auto bottomPlayerPos=position{};
    bottomPlayerPos.x = 480.0f-23.8f;  //Bottom Players Initial X-Position
    bottomPlayerPos.y = 540.0f-57.f;   //Bottom Players Initial Y-Position
    BulletPositionVector bulVecPos; 
    //Set bullet coordinates to that of the top players initial coordinates(middle of screen)
    bullet.setBulletPosition(LASER_CANNON_2); 
    topBulletPos=bullet.getBulletPosition(LASER_CANNON_2);
    bulVecPos.push_back(topBulletPos);
   
    for(unsigned int i=0; i< 151; i++)
    {
         bullet.moveBulletDown();
    }
     topBulletPos=bullet.getBulletPosition(LASER_CANNON_2);
     bulVecPos.push_back(topBulletPos);
    CHECK(collision.Bullet_Player(bottomPlayerPos,bulVecPos));
}

TEST_CASE("Check That There Is Collision Is Detected Between Bottom Player And Top Bullet From Top Player In The Far Left Of The Screen")
{ 
    //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto bullet=Bullet{};
    auto topBulletPos=position{};
    auto bottomPlayerPos=position{};
    bottomPlayerPos.x = 1.2f;  //Bottom Players X-Position At The Left Boundry
    bottomPlayerPos.y = 540.0f-57.f;   //Bottom Players Initial Y-Position
    BulletPositionVector bulVecPos; 
    //Set bullet coordinates to that of the top players initial coordinates(middle of screen)
    bullet.setBulletPosition(LASER_CANNON_2); 
    topBulletPos=bullet.getBulletPosition(LASER_CANNON_2);
    bulVecPos.push_back(topBulletPos);
    
    
   for(unsigned int i=0; i< 151; i++)
    {
         bullet.moveBulletDown();
    }
     topBulletPos=bullet.getBulletPosition(LASER_CANNON_2);
     topBulletPos.x=bottomPlayerPos.x;
     //Move Player The Top Player To The Left and shoot
     bulVecPos.push_back(topBulletPos);
     
    CHECK(collision.Bullet_Player(bottomPlayerPos,bulVecPos));
    
}
TEST_CASE("Check That There Is Collision Is Detected Between Bottom Player And Top Bullet From Top Player In The Far Right Of The Screen")
{ 
    //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto bullet=Bullet{};
    auto topBulletPos=position{};
    auto bottomPlayerPos=position{};
    bottomPlayerPos.x = 1.2f;  //Bottom Players X-Position At The Left Boundry
    bottomPlayerPos.y = 540.0f-57.f;   //Bottom Players Initial Y-Position
    BulletPositionVector bulVecPos; 
    //Set bullet coordinates to that of the top players initial coordinates(middle of screen)
    bullet.setBulletPosition(LASER_CANNON_2); 
    topBulletPos=bullet.getBulletPosition(LASER_CANNON_2);
    bulVecPos.push_back(topBulletPos);
    
    
   for(unsigned int i=0; i< 151; i++)
    {
         bullet.moveBulletDown();
    }
     topBulletPos=bullet.getBulletPosition(LASER_CANNON_2);
     topBulletPos.x=bottomPlayerPos.x;
     //Move Player The Top Player To The Left and shoot
     bulVecPos.push_back(topBulletPos);
     
    CHECK(collision.Bullet_Player(bottomPlayerPos,bulVecPos));
    
}

TEST_CASE("Check That No Collision Is Detected Between Top Player And Bottom Bullet From Bottom Player")
{ 
    //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto bullet=Bullet{};
    auto bottomBulletPos=position{};
    auto topPlayerPos=position{};
    topPlayerPos.x = 480.0f-23.8f;  //Bottom Players Initial X-Position
    topPlayerPos.y = 0.f;   //Bottom Players Initial Y-Position
    BulletPositionVector bulVecPos; 
    //Set bullet coordinates to that of the top players initial coordinates(middle of screen)
    bullet.setBulletPosition(LASER_CANNON_1); 
    bottomBulletPos=bullet.getBulletPosition(LASER_CANNON_1);
    bulVecPos.push_back(bottomBulletPos);
    CHECK_FALSE(collision.Bullet_Player(topPlayerPos,bulVecPos));
}

TEST_CASE("Check That There Is Collision Is Detected Between Top Player And The Bullet From Bottom Player In The Middle Of The Screen")
{ 
    //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto bullet=Bullet{};
    auto bottomBulletPos=position{};
    auto topPlayerPos=position{};
    topPlayerPos.x = 480.0f-23.8f;  //Bottom Players Initial X-Position
    topPlayerPos.y = 0.f;   //Bottom Players Initial Y-Position
    BulletPositionVector bulVecPos; 
    //Set bullet coordinates to that of the top players initial coordinates(middle of screen)
    bullet.setBulletPosition(LASER_CANNON_1); 
    bottomBulletPos=bullet.getBulletPosition(LASER_CANNON_1);
    bulVecPos.push_back(bottomBulletPos);
      for(unsigned int i=0; i< 151; i++)
    {
         bullet.moveBulletUp();
    }
    bottomBulletPos=bullet.getBulletPosition(LASER_CANNON_1);
    bulVecPos.push_back(bottomBulletPos);
    CHECK(collision.Bullet_Player(topPlayerPos,bulVecPos));
}

TEST_CASE("Check That There Is Collision Is Detected Between Top Player And The Bullet From Bottom Player In The Far Left Of The Screen")
{ 
    //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto bullet=Bullet{};
    auto bottomBulletPos=position{};
    auto topPlayerPos=position{};
    topPlayerPos.x = 1.2f;  //TopPlayers Initial X-Position
    topPlayerPos.y = 0.f;   //Top Players Initial Y-Position
    BulletPositionVector bulVecPos; 
    //Set bullet coordinates to that of the top players initial coordinates(middle of screen)
    bullet.setBulletPosition(LASER_CANNON_1); 
    bottomBulletPos=bullet.getBulletPosition(LASER_CANNON_1);
    bulVecPos.push_back(bottomBulletPos);
      for(unsigned int i=0; i< 151; i++)
    {
         bullet.moveBulletUp();
    }
    bottomBulletPos=bullet.getBulletPosition(LASER_CANNON_1);
    bottomBulletPos.x=topPlayerPos.x;
    
    bulVecPos.push_back(bottomBulletPos);
    CHECK(collision.Bullet_Player(topPlayerPos,bulVecPos));
}

TEST_CASE("Check That There Is Collision Is Detected Between Top Player And The Bullet From Bottom Player In The Far Right Of The Screen")
{ 
    //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto bullet=Bullet{};
    auto bottomBulletPos=position{};
    auto topPlayerPos=position{};
    topPlayerPos.x = 911.2f;  //TopPlayers Initial X-Position
    topPlayerPos.y = 0.f;   //Top Players Initial Y-Position
    BulletPositionVector bulVecPos; 
    //Set bullet coordinates to that of the top players initial coordinates(middle of screen)
    bullet.setBulletPosition(LASER_CANNON_1); 
    bottomBulletPos=bullet.getBulletPosition(LASER_CANNON_1);
    bulVecPos.push_back(bottomBulletPos);
      for(unsigned int i=0; i< 151; i++)
    {
         bullet.moveBulletUp();
    }
    bottomBulletPos=bullet.getBulletPosition(LASER_CANNON_1);
    bottomBulletPos.x=topPlayerPos.x;
    
    bulVecPos.push_back(bottomBulletPos);
    CHECK(collision.Bullet_Player(topPlayerPos,bulVecPos));
}
     
    
