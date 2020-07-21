#include "Player.h"
Player::Player()
{
 BottomPlayerPosition_ = position{setup.getWidth()/2.f-23.8f,setup.getHeight()-57.f};
 TopPlayerPosition_ = position{setup.getWidth()/2.f-23.8f, 0.0f}; 
 
 BottomPlayerInitlPosition = position{setup.getWidth()/2.f - 23.8f,setup.getHeight()/1.0f};
 TopPlayerInitlPosition = position{setup.getWidth()/2.f - 23.8f, 0.0f};
}
void Player::topPlayerMoveLeft()
{
    if((TopPlayerPosition_.x > boundary.getBounds(LASER_CANNON_2).w) ||  TopPlayerPosition_.x>1.5f)
    {
       TopPlayerPosition_.x -=playerSpeed;
      
    }

}
void Player::topPlayerMoveRight()
{
    if((TopPlayerPosition_.x < setup.getWidth() - boundary.getBounds(LASER_CANNON_2).w))
    {
       TopPlayerPosition_.x +=playerSpeed;
    }
}
void Player::bottomPlayerMoveLeft()
{
    if((BottomPlayerPosition_.x> 1.5f && BottomPlayerPosition_.y > 476.f) || (BottomPlayerPosition_.y == 0.f && BottomPlayerPosition_.x > 1.5f))    
        {
            BottomPlayerPosition_.x -= playerSpeed;
        }
}
void Player::bottomPlayerMoveRight()
{
    if((BottomPlayerPosition_.x < setup.getWidth() - boundary.getBounds(LASER_CANNON_1).w && BottomPlayerPosition_.y > 476.f) || (BottomPlayerPosition_.x < setup.getWidth() - boundary.getBounds(LASER_CANNON_1).w && BottomPlayerPosition_.y == 0.f))
    {
       BottomPlayerPosition_.x +=playerSpeed;

    }
}
position Player::BottomPlayerPosition()
{
    return BottomPlayerPosition_;
}
position Player::TopPlayerPosition()
{
    return TopPlayerPosition_;
}
position Player::BottomPlayerInitPosition()
{
      
    return  BottomPlayerInitlPosition;
}
position Player::TopPlayerInitPosition()
{
    return TopPlayerInitlPosition;
}

