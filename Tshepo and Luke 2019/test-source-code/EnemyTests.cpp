#include "Enemy.h"

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

////---------Enemy Movement Test------------/////

TEST_CASE("Check If Positions Of The Bottom Half Armadas Is Set Correctly")
{
    auto armadaBottom = Enemy {};
    auto temp = position{};
    vector<std::shared_ptr<position>>expected_position;
    vector<float>expected_xPos{};
    vector<float>expected_yPos{};
    vector<float>get_xPos{};
    vector<float>get_yPos{};
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 280.f + row * 30.f;
                expected_position.push_back(std::make_shared<position>(temp));
              }
     }
    
    for(unsigned int i=0; i<expected_position.size(); i++)
          {
             expected_xPos.push_back(expected_position[i]->x);
             expected_yPos.push_back(expected_position[i]->y);
           }

    vector<std::shared_ptr<position>>get_position= armadaBottom.BottomAlienPosition();
    for(unsigned int i=0; i<get_position.size(); i++)
         { 
            get_xPos.push_back(get_position[i]->x);
            get_yPos.push_back(get_position[i]->y);
         }

    CHECK(get_xPos==expected_xPos);
    CHECK(get_yPos==expected_yPos);
}

TEST_CASE("Check If Positions Of The Top Half Armadas Is Set Correctly")
{
    auto armadaTop = Enemy {};
    auto temp = position{};
    vector<std::shared_ptr<position>>expected_position;
    vector<float>expected_xPos{};
    vector<float>expected_yPos{};
    vector<float>get_xPos{};
    vector<float>get_yPos{};
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 240.f - row * 30.f;
                expected_position.push_back(std::make_shared<position>(temp));
              }
     }
    
    for(unsigned int i=0; i<expected_position.size(); i++)
          {
             expected_xPos.push_back(expected_position[i]->x);
             expected_yPos.push_back(expected_position[i]->y);
           }

    vector<std::shared_ptr<position>>get_position= armadaTop.TopAliensPosition();
    for(unsigned int i=0; i<get_position.size(); i++)
         { 
            get_xPos.push_back(get_position[i]->x);
            get_yPos.push_back(get_position[i]->y);
         }
    CHECK(get_xPos==expected_xPos);
    CHECK(get_yPos==expected_yPos);
}

TEST_CASE("Check If All The Bottom Half Armadas Can Move Down Correctly")
{
    auto armadaBottom = Enemy {};
    auto temp = position{};
    auto speed= 10.0f;
    vector<std::shared_ptr<position>>expected_position;
    vector<float>expected_xPos{};
    vector<float>expected_yPos{};
    vector<float>get_xPos{};
    vector<float>get_yPos{};
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 280.f + row * 30.f;
                expected_position.push_back(std::make_shared<position>(temp));
              }
     }

    for(auto element: expected_position)
        {
           element->y+=speed;
        }
    
    for(unsigned int i=0; i<expected_position.size(); i++)
       {
         expected_xPos.push_back(expected_position[i]->x);
         expected_yPos.push_back(expected_position[i]->y);
       }
     armadaBottom.moveDown();
     vector<std::shared_ptr<position>>get_position= armadaBottom.BottomAlienPosition();

    for(unsigned int i=0; i<get_position.size(); i++)
        { 
          get_xPos.push_back(get_position[i]->x);
          get_yPos.push_back(get_position[i]->y);
        }

      CHECK(get_xPos==expected_xPos);
      CHECK(get_yPos==expected_yPos);
}
TEST_CASE("Check If All The Top Half Armadas Can Move Up Correctly")
{
    auto armadaTop = Enemy {};
    auto temp = position{};
    auto speed= 10.0f;
    vector<std::shared_ptr<position>>expected_position;
    vector<float>expected_xPos{};
    vector<float>expected_yPos{};
    vector<float>get_xPos{};
    vector<float>get_yPos{};
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 240.f - row * 30.f;
                expected_position.push_back(std::make_shared<position>(temp));
              }
     }

    for(auto element: expected_position)
        {
           element->y-=speed;
        }
    
    for(unsigned int i=0; i<expected_position.size(); i++)
       {
         expected_xPos.push_back(expected_position[i]->x);
         expected_yPos.push_back(expected_position[i]->y);
       }
     armadaTop.moveUp();
     vector<std::shared_ptr<position>>get_position= armadaTop.TopAliensPosition();

    for(unsigned int i=0; i<get_position.size(); i++)
        { 
          get_xPos.push_back(get_position[i]->x);
          get_yPos.push_back(get_position[i]->y);
        }

      CHECK(get_xPos==expected_xPos);
      CHECK(get_yPos==expected_yPos);
}

TEST_CASE("Check If All The Bottom Half Armadas Can Move Down Correctly When They Reach Right Boundry")
{
    auto armadaBottom = Enemy {};
    auto temp = position{};
    auto speed= 10.0f;
    vector<std::shared_ptr<position>>expected_position;
    vector<float>expected_xPos{};
    vector<float>expected_yPos{};
    vector<float>get_xPos{};
    vector<float>get_yPos{};
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 280.f + row * 30.f;
                expected_position.push_back(std::make_shared<position>(temp));
              }
     }

    for(auto element: expected_position)
        {
           element->y+=speed;
        }
    
    for(unsigned int i=0; i<expected_position.size(); i++)
       {
         expected_yPos.push_back(expected_position[i]->y);
       }

     for(auto z=0u; z<240; z++) //The last alien x postion is 720 hence only 240 left to reach left boundary(Screen width=960)
     {
         armadaBottom.move();
     }
     vector<std::shared_ptr<position>>get_position= armadaBottom.BottomAlienPosition();

    for(unsigned int i=0; i<get_position.size(); i++)
        { 
          get_yPos.push_back(get_position[i]->y);
        }
      CHECK(get_yPos==expected_yPos);
}

TEST_CASE("Check If All The Top Half Armadas Can Move Up Correctly When They Reach Right Boundry")
{
    auto armadaTop = Enemy {};
    auto temp = position{};
    auto speed= 10.0f;
    vector<std::shared_ptr<position>>expected_position;
    vector<float>expected_xPos{};
    vector<float>expected_yPos{};
    vector<float>get_xPos{};
    vector<float>get_yPos{};
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                 temp.y = 240.f - row * 30.f;
                expected_position.push_back(std::make_shared<position>(temp));
              }
     }

    for(auto element: expected_position)
        {
           element->y-=speed;
        }
    
    for(unsigned int i=0; i<expected_position.size(); i++)
       {
         expected_yPos.push_back(expected_position[i]->y);
       }

     for(auto z=0u; z<240; z++) //The last alien x postion is 720 hence only 240 left to reach left boundary(Screen width=960)
     {
         armadaTop.move();
     }
     vector<std::shared_ptr<position>>get_position= armadaTop.TopAliensPosition();

    for(unsigned int i=0; i<get_position.size(); i++)
        { 
          get_yPos.push_back(get_position[i]->y);
        }
      CHECK(get_yPos==expected_yPos);
}

TEST_CASE("Check If All The Bottom Half Armadas Can Move Down Correctly When They Reach Left Boundry")
{
    auto armadaBottom = Enemy {};
    auto temp = position{};
    auto speed= 20.0f; //Expected Armadas to twice down as they first reach right boundary and then left boundary 
    vector<std::shared_ptr<position>>expected_position;
    vector<float>expected_xPos{};
    vector<float>expected_yPos{};
    vector<float>get_xPos{};
    vector<float>get_yPos{};
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                temp.y = 280.f + row * 30.f;
                expected_position.push_back(std::make_shared<position>(temp));
              }
     }

    for(auto element: expected_position)
        {
           element->y+=speed;
        }
    
    for(unsigned int i=0; i<expected_position.size(); i++)
       {
         expected_yPos.push_back(expected_position[i]->y);
       }
//The last alien x postion is 720 hence only 240 left to reach right boundary,240 to boundary(Screen width=960)
//240 again to reach left boundary. Thus Total is 480
     for(auto z=0u; z<480; z++) 
     {
         armadaBottom.move();
     }
     vector<std::shared_ptr<position>>get_position= armadaBottom.BottomAlienPosition();

    for(unsigned int i=0; i<get_position.size(); i++)
        { 
          get_yPos.push_back(get_position[i]->y);
        }
      CHECK(get_yPos==expected_yPos);
}

TEST_CASE("Check If All The Top Half Armadas Can Move Up Correctly When They Reach Left Boundary Boundry")
{
    auto armadaTop = Enemy {};
    auto temp = position{};
    auto speed= 20.0f; //Expected Armadas to twice down as they first reach right boundary and then left boundary 
    vector<std::shared_ptr<position>>expected_position;
    vector<float>expected_xPos{};
    vector<float>expected_yPos{};
    vector<float>get_xPos{};
    vector<float>get_yPos{};
    for(int row = 0; row < 3; row++) 
      { 
          for(int col = 0; col < 8; col++)
              {
                temp.x =80.f + col *80.f;
                 temp.y = 240.f - row * 30.f;
                expected_position.push_back(std::make_shared<position>(temp));
              }
     }

    for(auto element: expected_position)
        {
           element->y-=speed;
        }
    
    for(unsigned int i=0; i<expected_position.size(); i++)
       {
         expected_yPos.push_back(expected_position[i]->y);
       }
//The last alien x postion is 720 hence only 240 left to reach right boundary,240 to boundary(Screen width=960)
//240 again to reach left boundary. Thus Total is 480

     for(auto z=0u; z<480; z++) 
     {
         armadaTop.move();
     }
     vector<std::shared_ptr<position>>get_position= armadaTop.TopAliensPosition();

    for(unsigned int i=0; i<get_position.size(); i++)
        { 
          get_yPos.push_back(get_position[i]->y);
        }
      CHECK(get_yPos==expected_yPos);
}