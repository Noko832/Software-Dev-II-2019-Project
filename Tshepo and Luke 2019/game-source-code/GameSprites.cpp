#include "GameSprites.h"

GameSprites::GameSprites()
{
    playerOne.loadFromFile("player1.png");
    playerOne.setSmooth(true);
    playerOneSprite.setTexture(playerOne);
    
     playerTwo.loadFromFile("player2.png");
     playerTwo.setSmooth(true);
    playerTwoSprite.setTexture(playerTwo);
    
    alien.loadFromFile("red_galaxian.png");
    alienSprite.setTexture(alien);
      
    bullet.loadFromFile("bullet.png");
    bulletSprite.setTexture(bullet);
    bullet.setSmooth(true);
    
     screen_.loadFromFile("screen.png");
     screenSprite.setTexture(screen_);
     
     background.loadFromFile("gameBackground.png");
     backgroundSprite.setTexture(background);
     
      background2.loadFromFile("gameOverScreen.png");
      loseSprite.setTexture(background2);
   
      background3.loadFromFile("winScreen.png");
      winSprite.setTexture(background3);


}
sf::Sprite& GameSprites::getSprite(IDENTIFIER identifier)
{
    if( identifier == LASER_CANNON_1)
    return playerOneSprite;
    else if(identifier== LASER_CANNON_2)
    return playerTwoSprite;
    else if(identifier== BULLET)
    return bulletSprite;
    else if(identifier == SCREEN)
        return screenSprite;
    else if (identifier== ALIEN_ARMADA)
       return alienSprite;
    else if(identifier== BACKGROUND)
        return backgroundSprite;
    else if(identifier== BACKGROUND2)
        return winSprite;
    else if(identifier== BACKGROUND3)
        return loseSprite;
    else
       return alienSprite;
    
}
GameSprites::~GameSprites()
{
}
