#include "Collision.h"
#include "Bullet.h"

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

////-------------Bullet Alien Collision Test------------/////

TEST_CASE("Check That There's No Collision Detected Initially With The Bottom Aliens")
{
    EnemyPositionVector aliens_expectedPos;
    BulletPositionVector bulVecPos;
    auto collision= Collision{};
    auto temp = position{};
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 280.f + row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
    auto bullet=Bullet{};
    bullet.setBulletPosition(LASER_CANNON_1); 
    auto bottomBulletPos=position{};
    bottomBulletPos=bullet.getBulletPosition(LASER_CANNON_1);
    bulVecPos.push_back(bottomBulletPos);
    auto aliens_initialSize=aliens_expectedPos.size();
    auto bulVecPos_initialSize= bulVecPos.size();
    collision.Bullet_Aliens(aliens_expectedPos, bulVecPos);
    CHECK(aliens_expectedPos.size()==aliens_initialSize);
    CHECK(bulVecPos.size()==bulVecPos_initialSize);
}
TEST_CASE("Check That There's Collision Detected When Bullet Is In The Middle Of The Screen")
{
    EnemyPositionVector aliens_expectedPos;
    BulletPositionVector bulVecPos;
    auto collision= Collision{};
    auto temp = position{};
    //Setting Aliens Initial Position
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 280.f + row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
    auto bullet=Bullet{};
    bullet.setBulletPosition(LASER_CANNON_1); 
    auto bottomBulletPos=position{};
    bottomBulletPos=bullet.getBulletPosition(LASER_CANNON_1);
    bulVecPos.push_back(bottomBulletPos);
    auto shiftSpeed=56.2f;
    //Moving Aliens To The Middle Of The Screen
    for(auto z: aliens_expectedPos)
         z->x+=shiftSpeed;
    //Moving the bullet to the middle of the screen
    for(unsigned int i=0; i< 67; i++)
    {
         bullet.moveBulletUp();
    }
    //When collision occurs, objects are deleted
     bottomBulletPos=bullet.getBulletPosition(LASER_CANNON_1);
     bulVecPos.push_back(bottomBulletPos);
     auto aliens_initialSize=aliens_expectedPos.size();
     auto bulVecPos_initialSize= bulVecPos.size();
    collision.Bullet_Aliens(aliens_expectedPos, bulVecPos);
    CHECK_FALSE(aliens_expectedPos.size()==aliens_initialSize);
    CHECK_FALSE(bulVecPos.size()==bulVecPos_initialSize);
}

TEST_CASE("Check That There's Collision Detected When Bullet Is In The Middle Of The Screen At The left Boundary")
{
    EnemyPositionVector aliens_expectedPos;
    BulletPositionVector bulVecPos;
    auto collision= Collision{};
    auto temp = position{};
    //Setting Aliens Initial Position
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 280.f + row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
      //Move Aliens to the far left
      auto right_speed=80.f;
      for(auto element:aliens_expectedPos)
        {
            element->x-=right_speed;
        }
    auto bullet=Bullet{};
    bullet.setBulletPosition(LASER_CANNON_1); 
    auto bottomBulletPos=position{};
    bottomBulletPos=bullet.getBulletPosition(LASER_CANNON_1);
    bulVecPos.push_back(bottomBulletPos);
    //Moving the bullet to the middle of the screen
    for(unsigned int i=0; i< 67; i++)
    {
         bullet.moveBulletUp();
    }
     bottomBulletPos=bullet.getBulletPosition(LASER_CANNON_1);
     bottomBulletPos.x=1.2f; //Move Bullet to the left boundary
     bulVecPos.push_back(bottomBulletPos);
     //When collision occurs, objects are deleted
     auto aliens_initialSize=aliens_expectedPos.size();
     auto bulVecPos_initialSize= bulVecPos.size();
    collision.Bullet_Aliens(aliens_expectedPos, bulVecPos);
    CHECK_FALSE(aliens_expectedPos.size()==aliens_initialSize);
    CHECK_FALSE(bulVecPos.size()==bulVecPos_initialSize);
}
TEST_CASE("Check That There's Collision Detected When Bullet Is In The Middle Of The Screen At The Right Boundary")
{
    EnemyPositionVector aliens_expectedPos;
    BulletPositionVector bulVecPos;
    auto collision= Collision{};
    auto temp = position{};
    //Setting Aliens Initial Position
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 280.f + row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
      //Move Aliens to the far right
      auto right_speed=250.f;
      for(auto element:aliens_expectedPos)
        {
            element->x+=right_speed;
        }
    auto bullet=Bullet{};
    bullet.setBulletPosition(LASER_CANNON_1); 
    auto bottomBulletPos=position{};
    bottomBulletPos=bullet.getBulletPosition(LASER_CANNON_1);
    bulVecPos.push_back(bottomBulletPos);
    //Moving the bullet to the middle of the screen
    for(unsigned int i=0; i< 67; i++)
    {
         bullet.moveBulletUp();
    }
     bottomBulletPos=bullet.getBulletPosition(LASER_CANNON_1);
     bottomBulletPos.x=911.2f; //Move Bullet to the left boundary
     bulVecPos.push_back(bottomBulletPos);
     //When collision occurs, objects are deleted
     auto aliens_initialSize=aliens_expectedPos.size();
     auto bulVecPos_initialSize= bulVecPos.size();
    collision.Bullet_Aliens(aliens_expectedPos, bulVecPos);
    CHECK_FALSE(aliens_expectedPos.size()==aliens_initialSize);
    CHECK_FALSE(bulVecPos.size()==bulVecPos_initialSize);
}
TEST_CASE("Check That There's No Collision Detected Initially With The Top Aliens")
{
    EnemyPositionVector aliens_expectedPos;
    BulletPositionVector bulVecPos;
    auto collision= Collision{};
    auto temp = position{};
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 240.f - row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
    auto bullet=Bullet{};
    bullet.setBulletPosition(LASER_CANNON_2); 
    auto topBulletPos=position{};
    topBulletPos=bullet.getBulletPosition(LASER_CANNON_2);
    bulVecPos.push_back(topBulletPos);
    auto aliens_initialSize=aliens_expectedPos.size();
    auto bulVecPos_initialSize= bulVecPos.size();
    collision.Bullet_Aliens(aliens_expectedPos, bulVecPos);
    CHECK(aliens_expectedPos.size()==aliens_initialSize);
    CHECK(bulVecPos.size()==bulVecPos_initialSize);
}

TEST_CASE("Check That There's Collision Detected In The Middle Of The Screen With The Top Aliens  Left Boundry")
{
    EnemyPositionVector aliens_expectedPos;
    BulletPositionVector bulVecPos;
    auto collision= Collision{};
    auto temp = position{};
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 240.f - row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
    auto bullet=Bullet{};
    bullet.setBulletPosition(LASER_CANNON_2); 
    auto topBulletPos=position{};
    topBulletPos=bullet.getBulletPosition(LASER_CANNON_2);
    bulVecPos.push_back(topBulletPos);
    auto shiftSpeed=80.f;
    //Moving Aliens To The Middle Of The Screen
    for(auto z: aliens_expectedPos)
         z->x-=shiftSpeed;
    //Moving the bullet to the middle of the screen
    for(unsigned int i=0; i< 57; i++)
    {
          bullet.moveBulletDown();
    }
     topBulletPos=bullet.getBulletPosition(LASER_CANNON_2);
     topBulletPos.x=1.2f; //Move Bullet to the left boundary
     bulVecPos.push_back(topBulletPos);
    auto aliens_initialSize=aliens_expectedPos.size();
    auto bulVecPos_initialSize= bulVecPos.size();
    collision.Bullet_Aliens(aliens_expectedPos, bulVecPos);
    CHECK_FALSE(aliens_expectedPos.size()==aliens_initialSize);
    CHECK_FALSE(bulVecPos.size()==bulVecPos_initialSize);
}

TEST_CASE("Check That There's Collision Detected In The Middle Of The Screen With The Top Aliens Right Boundry")
{
    EnemyPositionVector aliens_expectedPos;
    BulletPositionVector bulVecPos;
    auto collision= Collision{};
    auto temp = position{};
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 240.f - row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
    auto bullet=Bullet{};
    bullet.setBulletPosition(LASER_CANNON_2); 
    auto topBulletPos=position{};
    topBulletPos=bullet.getBulletPosition(LASER_CANNON_2);
    bulVecPos.push_back(topBulletPos);
    auto shiftSpeed=250.f;
    //Moving Aliens To The Middle Of The Screen
    for(auto z: aliens_expectedPos)
         z->x+=shiftSpeed;
    //Moving the bullet to the middle of the screen
    for(unsigned int i=0; i< 61; i++)
    {
          bullet.moveBulletDown();
    }
     topBulletPos=bullet.getBulletPosition(LASER_CANNON_2);
     topBulletPos.x=911.2f; //Move Bullet to the left boundary
     bulVecPos.push_back(topBulletPos);
    auto aliens_initialSize=aliens_expectedPos.size();
    auto bulVecPos_initialSize= bulVecPos.size();
    collision.Bullet_Aliens(aliens_expectedPos, bulVecPos);
    CHECK_FALSE(aliens_expectedPos.size()==aliens_initialSize);
    CHECK_FALSE(bulVecPos.size()==bulVecPos_initialSize);
}
   

