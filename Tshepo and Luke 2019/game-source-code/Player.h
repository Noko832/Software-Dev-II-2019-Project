#ifndef PLAYER_H
#define PLAYER_H
#include "Setup.h"
#include "ObjectBounds.h"
#include <vector>

class Player
{
public:
/**
 * @brief Create a valid player object 
 */
     Player();
/**
 * @brief get the Bottom players position.
 * @return position of the Bottom player.
 */
     position BottomPlayerPosition();
/**
 * @brief get the Top players position.
 * @return position of the Top player.
 */
     position TopPlayerPosition();
 /**
 * @brief get the Bottom players initial position
 * @return initial position of the Bottom player
 */
     position BottomPlayerInitPosition();
 /**
 * @brief get the Top players initial position
 * @return initial position of the Top player
 */
     position TopPlayerInitPosition();
/**
 * @brief move Top player Left
 */
     void topPlayerMoveLeft();
/**
 * @brief move Top player Right.
 */
     void topPlayerMoveRight();
/**
 * @brief move Bottom player Right.
 */
     void bottomPlayerMoveLeft();
/**
 * @brief move Bottom player Right.
 */
     void bottomPlayerMoveRight();
private:
   float playerSpeed = 7.0f;
   position BottomPlayerPosition_;
   position TopPlayerPosition_;
    position BottomPlayerInitlPosition;
    position TopPlayerInitlPosition;
    ObjectBounds boundary;
   Setup setup; // needed for player initial position
};

#endif // PLAYER_H