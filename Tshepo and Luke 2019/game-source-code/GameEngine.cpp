#include "GameEngine.h"
GameEngine::GameEngine(std::shared_ptr<sf::RenderWindow> window) : window_ {window}
{
    pause_=FirstCollision=SecondCollision=ThirdCollision= ForthCollision=play=shooting= false;
    playerOne = mySprites.getSprite(LASER_CANNON_1);
    playerOne.setPosition(player.BottomPlayerInitPosition().x - 23.8f, player.BottomPlayerInitPosition().y - 57.f);
    playerTwo = mySprites.getSprite(LASER_CANNON_2);
    playerTwo.setPosition(player.TopPlayerInitPosition().x - 23.8f,player.TopPlayerInitPosition().y);
    bullet = mySprites.getSprite(BULLET);
    enemy_ = mySprites.getSprite(ALIEN_ARMADA);
    player_ = boundary.getBounds(LASER_CANNON_1);
    bullet_ = boundary.getBounds(BULLET);
    alien_ = boundary.getBounds(ALIEN_ARMADA);
}
void GameEngine::eventProcessing()
{
     while(window_->pollEvent(event)) 
       {
          DIRECTION userInput = input.getDirection();
          INSTRUCTION userInput2 = input.getInstruction();
          if(userInput == BOTTOM_LEFT ) 
              { 
                player.bottomPlayerMoveLeft();
                Update();
               }
        if(userInput == TOP_LEFT) 
             {
                player.topPlayerMoveLeft();
                Update();
              }
        if(userInput == BOTTOM_RIGHT) 
            {
                player.bottomPlayerMoveRight();
                Update();
            }
        if(userInput == TOP_RIGHT) 
            {
              player.topPlayerMoveRight();
              Update();
            }
        if(userInput2 == SHOOT_BOTTOM)
           {
             BottomPlayerShooting = true;
             BottomPlayerBullets.push_back(position{player.BottomPlayerPosition().x +18.0f, player.BottomPlayerPosition().y - 9.f});
            }
        if(userInput2 == SHOOT_TOP)
           {
             TopPlayerShooting = true;
             TopPlayerBullets.push_back(position { player.TopPlayerPosition().x + 18.f, player.TopPlayerPosition().y+ 50.f});
            }
       if(userInput2 == QUIT) {
          window_->close();
          }
        if(userInput2 == PLAY )
        {
            pause_ = false;
            play=true, FirstCollision=false, SecondCollision=false, ThirdCollision=false;
        }
       if(userInput2 == START) {
          play = true;
          }
       if(userInput2 == PAUSE)
        {
            pause_ = true;
            play = false;
            FirstCollision = true;
        }

        }
}
void GameEngine::Update()
{
    playerOne.setPosition(player.BottomPlayerPosition().x, player.BottomPlayerPosition().y);
    playerTwo.setPosition(player.TopPlayerPosition().x, player.TopPlayerPosition().y);
}
void GameEngine::Render()
{
    checkCollisions();
    enemy.move();
    window_->draw(playerOne);
    window_->draw(playerTwo);
    
    if(BottomPlayerShooting == true)
      {
        for(unsigned int i = 0; i < BottomPlayerBullets.size(); i++)
            {
                BottomPlayerBullets[i].y -= speed;
                bullet.setPosition(BottomPlayerBullets[i].x,BottomPlayerBullets[i].y);
                window_->draw(bullet);  
            }
     } 
      if(TopPlayerShooting==true)
      {
         for(unsigned int i = 0; i <TopPlayerBullets.size(); i++)
            {
                TopPlayerBullets[i].y += speed;
                bullet.setPosition(TopPlayerBullets[i].x,TopPlayerBullets[i].y);
                window_->draw(bullet); 
            }       
    }
    
}
void GameEngine::checkCollisions()
{
    auto temp = enemy.BottomAlienPosition();
    auto temp2 = enemy.TopAliensPosition();
    collision_.Bullet_Aliens(temp,BottomPlayerBullets);
    collision_.Bullet_Aliens(temp,TopPlayerBullets);
    collision_.Bullet_Aliens(temp2,BottomPlayerBullets);
    collision_.Bullet_Aliens(temp2,TopPlayerBullets);
    collision_.Bullet_Bullet(BottomPlayerBullets,TopPlayerBullets);
    enemy.update(temp, temp2);
    score = collision_.currentPoints();
    auto temp3 = player.BottomPlayerPosition();
    auto temp4 = player.TopPlayerPosition();
     FirstCollision =collision_.Alien_Player(temp3, temp);
     ForthCollision = collision_.Alien_Player(temp4, temp2);
     SecondCollision = collision_.Bullet_Player(temp3,TopPlayerBullets);
      ThirdCollision= collision_.Bullet_Player(temp4,BottomPlayerBullets);
if(FirstCollision == true || SecondCollision == true || ThirdCollision == true || ForthCollision == true)
    {
        play = false;
    }
    if(score==48)
    {
        play = false;
        FirstCollision = true;
    }
    for(auto z : temp)
    {
       enemy_.setPosition(z->x, z->y);
       window_->draw(enemy_);
    }
   for(auto z : temp2)
   {
     enemy_.setPosition(z->x, z->y);
     window_->draw(enemy_);
   }
}
int GameEngine::getScore()
{
  return score;
}
std::tuple<bool,bool,bool,bool,bool> GameEngine::getBoolean()
{

    return std::make_tuple(play,pause_,FirstCollision,SecondCollision,ThirdCollision);

}
GameEngine::~GameEngine()
{
    
}