#ifndef BULLET_H
#define BULLET_H
/**
 * @class Bullet
 * @author Tshepo Monene and Goitseona Mohajane
 * @date 26/09/2019
 * @file Bullet.h
 * @brief This class is responsible for modeling a bullet object
 */
#include "Player.h"
#include <tuple>
using bulletCoordinates = std::vector<float>;
class Bullet {
public:
/**
 * @brief Class constructor used to create a valid state object
 */
     Bullet();
/**
 * @brief Sets the bullet position.
 * @param identifier is the idenetifier used to identify the player(top or bottom player).
 */
     void setBulletPosition(IDENTIFIER identifier);
/**
 * @brief Moves the bullet in either the Upwards( bottom player) 
 */
      void moveBulletUp();
/**
 * @brief  Moves the bullet in either the Downwards ( bottom player) 
 */
      void moveBulletDown();
/**
 * @brief Gives the coordinates( x and y) of the bullet
 * @param identifier is the idenetifier used to identify the player(top or bottom player).
 * @return position is a 2D struct of floats (x,y)
 */
     position getBulletPosition(IDENTIFIER identifier);
     
private:
    position BottomPlayerBulletCoordinates; 
    position  TopPlayerBulletCoordinates; 
    const float vertical_speed=3.0f;
    Player player_; 
}; 
#endif