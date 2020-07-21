#include "Player.h"

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

//////----------------Player movement Test-------------------------/////
TEST_CASE("Check If Bottom Player Is Initialized To The Right Position")
{
    auto bottomPlayer=Player {};
    auto xinitial_expected = 480.0f-23.8f;
    auto yinitial_expected = 540.0f-57.f;
    CHECK(doctest::Approx(bottomPlayer.BottomPlayerPosition().x)== xinitial_expected);
    CHECK(doctest::Approx(bottomPlayer.BottomPlayerPosition().y)== yinitial_expected);
}

TEST_CASE("Check If Top Player Is Initialized To The Right Position")
{
   auto topPlayer=Player {};
   auto xPos_expected = 480.0f-23.8f;
   auto yPos_expected = 0.0f;
   CHECK(doctest::Approx(topPlayer.TopPlayerPosition().x)== xPos_expected);
   CHECK(doctest::Approx(topPlayer.TopPlayerPosition().y)== yPos_expected);
}

TEST_CASE("Check If The Bottom Player Moves To The Left And No Vertical Movement Is observed")
{
   auto bottomPlayer= Player{};
   auto speed= 7.0f;
   bottomPlayer.bottomPlayerMoveLeft();
   auto xPos_expected = (480.0f-23.8f)-speed;
   auto yPos_expected = 540.0f-57.f;
   CHECK(doctest::Approx(bottomPlayer.BottomPlayerPosition().x) == xPos_expected);
   CHECK(doctest::Approx(bottomPlayer.BottomPlayerPosition().y) == yPos_expected);
}

TEST_CASE("Check If The Top Player Moves To The Left And No Vertical Movement Is observed")
{
    auto topPlayer= Player{};
    auto speed= 7.0f;
    topPlayer.topPlayerMoveLeft();
    auto xPos_expected = (480.0f-23.8f)-speed;
    auto yPos_expected =0.0f;
    CHECK(doctest::Approx(topPlayer.TopPlayerPosition().x) == xPos_expected);
    CHECK(doctest::Approx(topPlayer.TopPlayerPosition().y) == yPos_expected);
}
TEST_CASE("Check That The bottom Player Moves To The Right And No Vertical Movement Is Observed")
{
   auto bottomPlayer= Player{};
   auto speed= 7.0f;
   bottomPlayer.bottomPlayerMoveRight();
   auto xPos_expected = (480.0f-23.8f)+speed;
   auto yPos_expected = 540.0f-57.f;
   CHECK(doctest::Approx(bottomPlayer.BottomPlayerPosition().x) == xPos_expected);
   CHECK(doctest::Approx(bottomPlayer.BottomPlayerPosition().y) == yPos_expected);
}
TEST_CASE("Check That The Top Player Moves To The Right And No Vertical Movement Is Observed")
{
   auto topPlayer= Player{};
   auto speed= 7.0f;
   topPlayer.topPlayerMoveRight();
   auto xPos_expected = (480.0f-23.8f)+speed;
   auto yPos_expected = 0;
   CHECK(doctest::Approx(topPlayer.TopPlayerPosition().x) == xPos_expected);
   CHECK(doctest::Approx(topPlayer.TopPlayerPosition().y) == yPos_expected);
}
TEST_CASE("Check That Bottom Player Cannot Be Move To Left When At The Left Boundary")
{
   auto bottomPlayer= Player{};
   for(auto z=0u; z<65;z++)
   bottomPlayer.bottomPlayerMoveLeft();
   auto xPos_expected = 1.2f;
   auto yPos_expected = 540.0f-57.f;
   CHECK(doctest::Approx(bottomPlayer.BottomPlayerPosition().x)==xPos_expected);
   bottomPlayer.bottomPlayerMoveLeft();
   CHECK(doctest::Approx(bottomPlayer.BottomPlayerPosition().x)==xPos_expected);
   CHECK(bottomPlayer.BottomPlayerPosition().y == yPos_expected);
}
TEST_CASE("Check That Top Player Cannot Be Moved To Left When At The Left Boundary")
{
   auto topPlayer= Player{};
   for(auto z=0u; z<65;z++)
   topPlayer.topPlayerMoveLeft();
   auto xPos_expected = 1.2f;
   auto yPos_expected = 0.f;
   CHECK(doctest::Approx(topPlayer.TopPlayerPosition().x)==xPos_expected);
   topPlayer.topPlayerMoveLeft();
   CHECK(doctest::Approx(topPlayer.TopPlayerPosition().x)==xPos_expected);
   CHECK(topPlayer.TopPlayerPosition().y == yPos_expected);
}
TEST_CASE("Check That Bottom Player Cannot Be Moved To The Right When At The Right Boundary")
{
   auto bottomPlayer= Player{};
   for(auto z=0u; z<65;z++)
   bottomPlayer.bottomPlayerMoveRight();
   auto xPos_expected = 911.2f;
   auto yPos_expected = 540.0f-57.f;
   CHECK(doctest::Approx(bottomPlayer.BottomPlayerPosition().x)==xPos_expected);
   bottomPlayer.bottomPlayerMoveRight();
   CHECK(doctest::Approx(bottomPlayer.BottomPlayerPosition().x)==xPos_expected);
   CHECK(bottomPlayer.BottomPlayerPosition().y == yPos_expected);
}
TEST_CASE("Check That The Top Player Cannot Be Moved To The Right When At The Right Boundary")
{
   auto topPlayer= Player{};
   for(auto z=0u; z<65;z++)
   topPlayer.topPlayerMoveRight();
   auto xPos_expected = 911.2f;
   auto yPos_expected = 0.f;
   CHECK(doctest::Approx(topPlayer.TopPlayerPosition().x)==xPos_expected);
   topPlayer.topPlayerMoveRight();
   CHECK(doctest::Approx(topPlayer.TopPlayerPosition().x)==xPos_expected);
   CHECK(topPlayer.TopPlayerPosition().y == yPos_expected);
}

TEST_CASE("Check If Moving Bottom Player To The Doesn't Affect Top Player")
{
    auto bottomPlayer=Player{};
    auto topPlayer=Player{};
    auto xinitial_expected = 480.0f-23.8f;
    auto yinitial_expected = 0.f;
    bottomPlayer.bottomPlayerMoveLeft();
    CHECK(doctest::Approx(topPlayer.TopPlayerPosition().x)== xinitial_expected);
    CHECK(doctest::Approx(topPlayer.TopPlayerPosition().y)== yinitial_expected);
    bottomPlayer.bottomPlayerMoveRight();
    CHECK(doctest::Approx(topPlayer.TopPlayerPosition().x)== xinitial_expected);
    CHECK(doctest::Approx(topPlayer.TopPlayerPosition().y)== yinitial_expected);
}
TEST_CASE("Check If Moving Top Player Doesn't Affect Bottom Player")
{
    auto bottomPlayer=Player{};
    auto topPlayer=Player{};
    auto xinitial_expected = 480.0f-23.8f;
    auto yinitial_expected = 540.0f-57.f;;
    bottomPlayer.topPlayerMoveLeft();
    CHECK(doctest::Approx(bottomPlayer.BottomPlayerPosition().x)== xinitial_expected);
    CHECK(doctest::Approx(bottomPlayer.BottomPlayerPosition().y)== yinitial_expected);
    bottomPlayer.topPlayerMoveRight();
    CHECK(doctest::Approx(bottomPlayer.BottomPlayerPosition().x)== xinitial_expected);
    CHECK(doctest::Approx(bottomPlayer.BottomPlayerPosition().y)== yinitial_expected);
}



