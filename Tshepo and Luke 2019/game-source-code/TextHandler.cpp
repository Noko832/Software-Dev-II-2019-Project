#include "TextHandler.h"

TextHandler::TextHandler(std::shared_ptr<sf::RenderWindow> window)
{
    if(window == nullptr)
    {
        throw WindowNotFound();
    }
    window_ = window;
}
void TextHandler::WelcomeScreenText()
{
    if(!WelcomeScreenFont.loadFromFile("sansation.ttf"))
       {
        throw "File not loaded";
       }
    sf::Text text;
    text.setFont(WelcomeScreenFont);
    text.setCharacterSize(20.f);
    text.setPosition(470.f, 10.f);
    text.setFillColor(sf::Color::Red);
    text.setString("Welcome to Dual Invaders! \n TWO PLAYER MODE \n\n"
    "------------------------------------------------------------------------------------------\n\n"
                 " Top Player Keys : \n move left[E]\n Move Right[T]\n Shoot[A]\n\n"
    "------------------------------------------------------------------------------------------\n\n"
                 " Bottom Player Keys : \n move left[<-]\n Move Right[->]\n Shoot[^]\n"
    "------------------------------------------------------------------------------------------\n\n\n"
                            "To quit the game Press [Q] \n To start Press [S] \n To pause press [P] \n To resume press[Enter]");
    window_->clear(sf::Color::Black); 
    window_->draw(text);
}
void TextHandler::PauseGameText()
{
    
     if(!PauseGameFont.loadFromFile("KaushanScript-Regular.otf"))
      {
         throw "File not loaded";
      }
    sf::Text text_;
    text_.setFont(PauseGameFont);
    text_.setCharacterSize(40);
    text_.setPosition(300.f, 30.f);
    text_.setFillColor(sf::Color::Red);
    text_.setString("You Paused the game\n\n\n To continue Press [Enter] \n\n\n To exit Press [Q]");
                             
   window_->clear(sf::Color::White);
    window_->draw(text_);
}
void TextHandler::GameOverText( int number)
{
    
     if(!GameOverFont.loadFromFile("KaushanScript-Regular.otf"))
      {
          throw "File not loaded";
      }
      
           sf::Text _text;
          _text.setFont(GameOverFont);
          _text.setCharacterSize(30.f);
          _text.setFillColor(sf::Color::White);
    
    if(number == 0)
    {
    _text.setPosition(300.f, 30.f);
    _text.setString("WELL DONE YOU WON\n\n\n PRESS [Q] TO EXIT THE GAME");
    window_->clear(sf::Color::Red);
    window_->draw(_text);
    }
    else if(number==1)
    {
    _text.setPosition(300.f,0.f);
    _text.setString("PRESS [Q] TO EXIT THE GAME");
    window_->clear(sf::Color::Red);
    }
}
TextHandler::~TextHandler()
{}