#ifndef GAMEENGINE_H
#define GAMEENGINE_H
/**
 * @class GameEngine
 * @author Tshepo Monene and Goitseona Mohajane
 * @date 26/09/2019
 * @file GameEngine.h
 * @brief This class is responsible for bringing everything together
 */
#include "Bullet.h"
#include "Collision.h"
#include "Enemy.h"
#include "GameSprites.h"
#include "KeyboardHandler.h"
using namespace std;
using EnemyVector = std::vector<std::shared_ptr<position>>;
using BulletVector = std::vector<position>;
class GameEngine
{
public:
/**
 * @brief renders the main window to draw entities
 */
    GameEngine(std::shared_ptr<sf::RenderWindow> window);
/**
 * @brief Updates screen after collisions
 */
    void Update();
/**
 * @brief Constantly checks for collisions 
 */
    void Render();
/**
 * @brief Checks for events triggered by user
 */
    void eventProcessing();
/**
 * @brief Checks for all collissions
 */
    void checkCollisions();
/**
 * @brief responsible for returning all boolean variables which control game flow 
 * @return play,pause,firstCollision, SecondCollision, ThirdCollision.
 */
    std::tuple<bool,bool,bool,bool,bool>getBoolean();
/**
 * @brief gets the number of aliens destroyed
 * @return the player score = number of aliens destroyed.
 */
    int getScore();

    ~GameEngine();
private :
    sf::Sprite  playerOne,playerTwo,enemy_,bullet,screen, screenBackground;
    sf::Event event;
    std::shared_ptr<sf::RenderWindow> window_;

    bool pause_,FirstCollision,SecondCollision,ThirdCollision, ForthCollision,play,shooting;
    bool TopPlayerShooting=false;
    bool  BottomPlayerShooting=false;
    int score = 0;
    float speed = 3.f;
    BulletVector BottomPlayerBullets,TopPlayerBullets;    
    
    dimensions player_, bullet_, alien_;
    ObjectBounds boundary;
    GameSprites mySprites;
    Player player;
     Bullet _bullet;
    KeyboardHandler input;
    Collision collision_;
    Enemy enemy;  
};

#endif // GAMEENGINE_H
