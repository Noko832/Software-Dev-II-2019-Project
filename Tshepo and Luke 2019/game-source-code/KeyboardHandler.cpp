#include "KeyboardHandler.h"

DIRECTION KeyboardHandler::getDirection()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return BOTTOM_LEFT;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        return TOP_LEFT;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return BOTTOM_RIGHT;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
        return TOP_RIGHT;
    else
        return NAN;
  
}

INSTRUCTION KeyboardHandler::getInstruction()
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        return QUIT;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        return PLAY;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        return START;
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        return PAUSE;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
       return SHOOT_TOP;
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    return SHOOT_BOTTOM;
  else 
    return NON;
}

