#ifndef GAMESPRITES_H
#define GAMESPRITES_H
/**
 * @class GameSprites
 * @author Tshepo Monene and Goitseona Mohajane
 * @date 26/09/2019
 * @file GameSprites.h
 * @brief 
 */
#include <SFML/Graphics.hpp>
#include "Types.h"

class GameSprites
{
public:
/**
 * @brief create a valid state object 
 */
     GameSprites();
/**
 * @brief gets the sprite identified by the player
 * @param identifier is the idenetifier used to identify the sprite
 * @return sprite of the entity
 */
     sf::Sprite& getSprite(IDENTIFIER identifier);
     
    ~GameSprites();


private :
 sf::Texture playerOne;
 sf::Texture playerTwo;
 sf::Texture bullet;
 sf::Texture alien;
 sf::Texture screen_;
 sf::Texture  background;
 sf::Texture  background2;
 sf::Texture  background3;
 sf::Sprite playerOneSprite;
 sf::Sprite playerTwoSprite;
 sf::Sprite bulletSprite;
 sf::Sprite alienSprite;
 sf::Sprite screenSprite;
 sf::Sprite backgroundSprite;
 sf::Sprite loseSprite;
 sf::Sprite winSprite;
 
 };

#endif // GAMESPRITES_H
