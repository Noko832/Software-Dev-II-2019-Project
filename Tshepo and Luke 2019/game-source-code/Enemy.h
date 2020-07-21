#ifndef ENEMY_H
#define ENEMY_H
/**
 * @class Enemy
 * @author Tshepo Monene and Goitseona Mohajane
 * @date 26/09/2019
 * @file Enemy.h
 * @brief 
 */

#include "Types.h"
#include <memory> 
#include <vector>
class Enemy
{
public:
 /**
  * @brief Creates a valid state enemy object.
  */
    Enemy();
 /**
  * @brief moves the alien/ enemy formation.
  */
    void move();
/**
 * @brief Updates the Bottom and Top Enemies.
 * @param aliens is a vector of shared_ptr which stores the position of each alien in the bottom formation.
 * @param aliens_ is a vector of shared_ptr which stores the position of each alien in the top formation.
 */
    void update(const std::vector<std::shared_ptr<position>> aliens, const std::vector<std::shared_ptr<position>> aliens_);
 /**
  * @brief Checks if the formation has hit the left or right boundary.
  */
    void boundaryChecker();
 /**
  * @brief Moves the formation down.
  */
    void moveDown();
/**
 * @brief moves the formation up.
 */
    void moveUp();
/**
 * @brief get the coordinates of each alien/ enemy in the bottom formation.
 */
  std::vector<std::shared_ptr<position>>BottomAlienPosition();
/**
 * @brief get the coordinates of each alien/ enemy in the Top formation.
 */
  std::vector<std::shared_ptr<position>>TopAliensPosition();
    ~Enemy();

private:
    float x_pos;
    float y_pos_;
    const float speed= 2.0f;
    bool leftBound=false;
    bool leftBound2=false;
    bool rightBound=true;
    bool rightBound2=true;
    position coordinates;
    std::vector<std::shared_ptr<position>> BottomAliens;
    std::vector<std::shared_ptr<position>> TopAliens;
};

#endif // ENEMY_H
