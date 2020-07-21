#include "Screen.h"
Screen::Screen()
    : window {new sf::RenderWindow{sf::VideoMode (960,540), "Dual Invaders"}}, message(window), gameEngine_(window)
{
    window->setFramerateLimit(60);
    window->setKeyRepeatEnabled(false);
    screen = mySprites.getSprite(SCREEN);
    screenBackground = mySprites.getSprite(BACKGROUND);
   
}

void Screen::eventprocessing()
{
    gameEngine_.eventProcessing();
}
void Screen::update()
{
  gameEngine_.Update(); 
}

void Screen::render()
{
window->draw(screenBackground);
gameEngine_.Render();
window->display();
}
void Screen::run()
{
        while(window->isOpen())
        {
                auto [play,pause, destroyed, destroyed2, destroyed3] = gameEngine_.getBoolean();
                auto score = gameEngine_.getScore();

                if(!play && !destroyed && !destroyed2 && !destroyed3)
                {
                   message.WelcomeScreenText();
                   window->draw(screen);
                   window->display();
                }
                if(pause && !play && destroyed)
                {
                    message.PauseGameText();
                   window->display();  
                }
                if(play) 
                {
                  render();
                }
            if((destroyed == true && !play && !pause && score!=48) || (destroyed2 == true && !play && !pause && score!=48) || (destroyed3 == true && !play && !pause && score!=48))
                {
                 message.GameOverText(1);
                 window->draw(mySprites.getSprite(BACKGROUND3));
                 window->display();
                }
            if(score == 48 && !play && destroyed)
            {
                message.GameOverText(0);
                window->draw(mySprites.getSprite(BACKGROUND2));
                window->display();
            }
              eventprocessing();
        
    }
}
