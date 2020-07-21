#ifndef TEXTHANDLER_H
#define TEXTHANDLER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include "Setup.h"
class WindowNotFound{};
/**
 * @class TextHandler
 * @author Tshepo Monene and Goitseona Mohajane
 * @date 26/09/2019
 * @file TextHandler.h
 * @brief 
 */
class TextHandler
{
public:
   /**
     * @brief renders the main window to draw the texts
     */
    TextHandler(std::shared_ptr<sf::RenderWindow> window);
    /**
     * @brief Draws welcome screen text
     */
    void WelcomeScreenText();
    /**
     * @brief Draws game over text
     * @param number is a int defining which game over text should be written if 0-> win if 1-> lose
     */
    void GameOverText(int number);
   /**
    * @brief Draws pause game text
    */
    void PauseGameText();
    ~TextHandler();
private :
  
  sf::Font WelcomeScreenFont, GameOverFont, PauseGameFont;
  Setup setup;
  std::shared_ptr<sf::RenderWindow> window_;
  
 
};

#endif // TEXTHANDLER_H
