#ifndef SCREEN_H
#define SCREEN_H
/**
 * @class Screen
 * @author Tshepo Monene and Goitseona Mohajane
 * @date 26/09/2019
 * @file Screen.h
 * @brief 
 */
#include "TextHandler.h"
#include "GameEngine.h"
class Screen  // Drawing on the screen
{
public:
   /**
    * @brief Create a valid screen object
    */
    Screen();
  /**
   * @brief Process all the events 
   */
    void eventprocessing();
    /**
     * @brief runs the main game
     */
    void run();
    /**
     * @brief update the screen
     */
    void update();
    /**
     * @brief drawing of texts
     */
    void render();
    
private:
  std::shared_ptr<sf::RenderWindow> window;
  sf::Sprite screen,screenBackground;
   TextHandler message;
  GameEngine gameEngine_;
  GameSprites mySprites;

};

#endif // SCREEN_H