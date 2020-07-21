#ifndef COLLISION_H
#define COLLISION_H
/**
 * @class Collision
 * @author Tshepo Monene and Goitseona Mohajane
 * @date 26/09/2019
 * @file Collision.h
 * @brief 
 */
#include "Types.h"
#include <cmath>
#include <vector>
#include <tuple>
#include <memory>

using namespace std;
using std::tuple;
using EnemyPositionVector = std::vector<std::shared_ptr<position>>;
using BulletPositionVector = std::vector<position>;
class Collision
{
public:
    /**
     * @brief Creates a valid collision object.
     */
    Collision();
    /**
     * @brief Checks for collision between bullets and aliens.
     * @param enemies is a vector of alien/ enemy positions.
     * @param bullets is a vector of bullet positions.
     */
    void Bullet_Aliens(EnemyPositionVector& enemies, BulletPositionVector& bullets);
    /**
     * @brief detects collision between alien/enemy and player.
     * @param playerCoordinates are the current coordinates of the player.
     * @param enemies is a vector containing each aliens/enemy coordinates.
     * @return true if the was a collision detected, false otherwise.
     */
    bool Alien_Player(position& playerCoordinates, EnemyPositionVector& enemies);
    /**
     * @brief detects collision between bullet and player.
     * @param playerCoordinates are the current coordinates of the player.
     * @param bullets is a vector containing the bullet coordinates.
     * @return true if the was a collision detected, false otherwise.
     */
    bool Bullet_Player(position& playerCoordinates, BulletPositionVector& bullets);
    /**
     * @brief detects collision between bottom player bullets and top player bullets.
     * @param bulletsOne is a vector containing the bullet coordinates of bottom player.
     * @param bulletsTwo is a vector containing the bullet coordinates of top player.
     */
    void Bullet_Bullet(BulletPositionVector& bulletsOne, BulletPositionVector& bulletsTwo);
    /**
     * @brief contains the points of the player
     * @return player points
     */
    int currentPoints();
    
    ~Collision();
    
private:
    float deltaX;
    float deltaY;
    int playerPoints;
    float distance;
   /**
     * @brief checks if two entities have collided.
     * @param x_ is the x position of entity 1.
     * @param y_ is the y position of entity 1.
     * @param x is the x position of entity 2.
     * @param y is the y position of entity 2.
     * @param radiusOne is the radius of entity 1.
     * @param radiusTwo is the radius of entity 1.
     * @return true if the was a collision detected, false otherwise.
     */
    bool checkCollision(float x_,float y_, float x, float y,float radiusOne, float radiusTwo);

};

#endif // COLLISION_H
