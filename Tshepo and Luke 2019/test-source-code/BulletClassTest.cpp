#include "Bullet.h"

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

///-------------Bullet Class Test------------/////
TEST_CASE("Check If The Class Intitializes Bullets Coordinates To That Of The Bottom Player")
{
    auto bottomBullet=Bullet{};
    auto bottomPlayer=position{};
    auto expected_xPos=480.0f-23.8f;
    auto expected_yPos=540.0f-57.f;
    bottomBullet.setBulletPosition(LASER_CANNON_1);
    bottomPlayer=bottomBullet.getBulletPosition(LASER_CANNON_1);
    CHECK(expected_xPos==bottomPlayer.x);
    CHECK(expected_yPos==bottomPlayer.y);
} 

TEST_CASE("Check If The Class Intitializes Bullets Coordinates To That Of Top Bottom Player")
{
    auto topBullet=Bullet{};
    auto topPlayer=position{};
    auto expected_xPos=480.0f-23.8f;
    auto expected_yPos=0.f;
    topBullet.setBulletPosition(LASER_CANNON_2);
    topPlayer=topBullet.getBulletPosition(LASER_CANNON_2);
    CHECK(expected_xPos==topPlayer.x);
    CHECK(expected_yPos==topPlayer.y);
}

TEST_CASE("Check If The Top Bullet Can Be Moved To The Bottom Of The Screen With Only A Change In Y-Direction")
{
    auto topBullet=Bullet{};
    auto topPlayer=position{};
    auto expected_xPos=480.0f-23.8f;
    auto expected_yPos=450.f;
    topBullet.setBulletPosition(LASER_CANNON_2);
    for(auto z=0u; z<150;z++)
        topBullet.moveBulletDown();
        
    topPlayer=topBullet.getBulletPosition(LASER_CANNON_2);
    CHECK(expected_xPos==topPlayer.x);
    CHECK(expected_yPos==topPlayer.y);
} 

TEST_CASE("Check If The Bottom Bullet Can Be Moved To The Top Of The Screen With Only A Change In Y-Direction")
{
    auto bottomBullet=Bullet{};
    auto bottomPlayer=position{};
    auto expected_xPos=480.0f-23.8f;
    auto expected_yPos=0.f;
    bottomBullet.setBulletPosition(LASER_CANNON_1);
    for(auto z=0u; z<161;z++)
        bottomBullet.moveBulletUp();
        
    bottomPlayer=bottomBullet.getBulletPosition(LASER_CANNON_1);
    CHECK(expected_xPos==bottomPlayer.x);
    CHECK(expected_yPos==bottomPlayer.y);
}