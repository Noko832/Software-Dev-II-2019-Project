#include "Collision.h"
#include "Player.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

//////----------------Alien Player Collision Test-------------------------/////
TEST_CASE("Check That No Collision Is Detected Between Bottom Player And Bottom Aliens Initially")
{ 
    //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto bottomPlayer=Player{};
    auto temp=position{};
    auto bottomPlayerPos=position{};
    EnemyPositionVector aliens_expectedPos;
    
    //Initializing Bottom Aliens Positions
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 280.f + row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
     
     //Obtain Bottom Player Position
     bottomPlayerPos=bottomPlayer.BottomPlayerPosition();

     //Check Collision Between Player And Alien
      CHECK_FALSE(collision.Alien_Player(bottomPlayerPos,aliens_expectedPos)); 

}
TEST_CASE("Check That No Collision Is Detected Between Top Player And Top Alien Initially")
{
     //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto topPlayer=Player{};
    auto temp=position{};
    auto topPlayerPos=position{};
    EnemyPositionVector aliens_expectedPos;
    
    //Initializing Top Aliens Positions
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                 temp.y = 240.f - row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
     
     //Obtain Top Player Position
     topPlayerPos=topPlayer.TopPlayerPosition();

     //Check Collision Between Player And Alien
      CHECK_FALSE(collision.Alien_Player(topPlayerPos,aliens_expectedPos)); 
}

TEST_CASE("Check That No Collision Is Detected Between Bottom Player And Top Aliens Initially")
{ 
    //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto bottomPlayer=Player{};
    auto temp=position{};
    auto bottomPlayerPos=position{};
    EnemyPositionVector aliens_expectedPos;
    
    //Initializing Bottom Aliens Positions
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 240.f - row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
     
     //Obtain Bottom Player Position
     bottomPlayerPos=bottomPlayer.BottomPlayerPosition();

     //Check Collision Between Player And Alien
      CHECK_FALSE(collision.Alien_Player(bottomPlayerPos,aliens_expectedPos)); 

}

TEST_CASE("Check That No Collision Is Detected Between Top Player And Bottom Alien Initially")
{
     //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto topPlayer=Player{};
    auto temp=position{};
    auto topPlayerPos=position{};
    EnemyPositionVector aliens_expectedPos;
    
    //Initializing Bottom Aliens Positions
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 280.f + row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
     
     //Obtain Top Player Position
     topPlayerPos=topPlayer.TopPlayerPosition();

     //Check Collision Between Player And Alien
      CHECK_FALSE(collision.Alien_Player(topPlayerPos,aliens_expectedPos)); 
}

TEST_CASE("Check That No Collision Is Detected Between Bottom Player And Bottom Aliens When Aliens Are Moved Two Rows Down")
{ 
    //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto bottomPlayer=Player{};
    auto temp=position{};
    auto bottomPlayerPos=position{};
    EnemyPositionVector aliens_expectedPos;
    auto speed=10.0f;
    
    //Initializing Bottom Aliens Positions
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 280.f + row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
     
     //Move Aliens Down Two Rows
     for(auto element: aliens_expectedPos)
        {
           element->y+=speed;
        }
     //Obtain Bottom Player Position
     bottomPlayerPos=bottomPlayer.BottomPlayerPosition();
     

     //Check Collision Between Player And Alien
      CHECK_FALSE(collision.Alien_Player(bottomPlayerPos,aliens_expectedPos)); 

}

TEST_CASE("Check That No Collision Is Detected Between Top Player And Top Aliens When Aliens Are Moved Two Rows Up")
{
     //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto topPlayer=Player{};
    auto temp=position{};
    auto topPlayerPos=position{};
    EnemyPositionVector aliens_expectedPos;
    auto speed=10.0f;
    
    //Initializing Top Aliens Positions
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                 temp.y = 240.f - row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
     
     //Obtain Top Player Position
     topPlayerPos=topPlayer.TopPlayerPosition();
     
     //Top Aliens Moved To Rows Up
      for(auto element: aliens_expectedPos)
        {
           element->y-=speed;
        }
     //Check Collision Between Player And Alien
      CHECK_FALSE(collision.Alien_Player(topPlayerPos,aliens_expectedPos)); 
}

TEST_CASE("Check That A Collision Is Detected Between Bottom Player And Bottom Aliens Move 15 Rows Down Both Boundries")
{ 
    //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto bottomPlayer=Player{};
    auto temp=position{};
    auto bottomPlayerPos=position{};
    EnemyPositionVector aliens_expectedPos;
    auto down_speed=10.0*15.f; //Moving aliens 17 rows down
    auto left_speed=80.0f;
    auto right_speed=351.f; // Moving aliens from far left to the right
    auto leftBound=1.2f;
    auto rightBound=911.2f;
    
    //Initializing Bottom Aliens Positions
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 280.f + row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
     //Move Aliens 15 rows down
     for(auto element: aliens_expectedPos)
        {
           element->y+=down_speed;
        }
        
     
     //Obtain Bottom Player Position
     bottomPlayerPos=bottomPlayer.BottomPlayerPosition();

     //Check Collision Between Player And Alien At The Center
      CHECK(collision.Alien_Player(bottomPlayerPos,aliens_expectedPos));
      //Move Aliens towards The Left Boundary
        for(auto element:aliens_expectedPos)
        {
            element->x-=left_speed;
        }
      //Move Bottom Player To The Left Boundary
      bottomPlayerPos.x=leftBound;
      CHECK(collision.Alien_Player(bottomPlayerPos,aliens_expectedPos)); 

      //Move Bottom Player To The Right Bound
      bottomPlayerPos.x=rightBound;
      //Move Aliens to the far right
      for(auto element:aliens_expectedPos)
        {
            element->x+=right_speed;
        }
      CHECK(collision.Alien_Player(bottomPlayerPos,aliens_expectedPos)); 
      
}

TEST_CASE("Check That A Collision Is Detected Between Top Player And Top Aliens Move 16 Rows Up and Both Boundries")
{ 
    //Variables That Will Be Needed To Test The Collision
    auto collision=Collision{};
    auto topPlayer=Player{};
    auto temp=position{};
    auto topPlayerPos=position{};
    EnemyPositionVector aliens_expectedPos;
    auto up_speed=10.0*16.f; //Moving aliens 16 rows up
    auto left_speed=80.0f;
    auto right_speed=351.f; // Moving aliens from far left to the right
    auto leftBound=1.2f;
    auto rightBound=911.2f;
    
    //Initializing Bottom Aliens Positions
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                 temp.y = 240.f - row * 30.f;
                aliens_expectedPos.push_back(std::make_shared<position>(temp));
              }
     }
     //Move Aliens 15 rows down
     for(auto element: aliens_expectedPos)
        {
           element->y-=up_speed;
        }
        
     
     //Obtain Bottom Player Position
     topPlayerPos=topPlayer.TopPlayerPosition();

     //Check Collision Between Player And Alien At The Center
      CHECK(collision.Alien_Player(topPlayerPos,aliens_expectedPos));
      //Move Aliens towards The Left Boundary
        for(auto element:aliens_expectedPos)
        {
            element->x-=left_speed;
        }
      //Move Bottom Player To The Left Boundary
      topPlayerPos.x=leftBound;
      CHECK(collision.Alien_Player(topPlayerPos,aliens_expectedPos)); 

      //Move Bottom Player To The Right Bound
      topPlayerPos.x=rightBound;
      //Move Aliens to the far left
      for(auto element:aliens_expectedPos)
        {
            element->x+=right_speed;
        }
      CHECK(collision.Alien_Player(topPlayerPos,aliens_expectedPos)); 
      
}

