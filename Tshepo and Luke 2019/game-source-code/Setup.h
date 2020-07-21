#ifndef SETUP_H
#define SETUP_H

class Setup
{
public:
int getWidth();
int getHeight();
int getTimeframe();
bool keyHandler();
private :
 const int width = 960;
 const int height = 540;
 const int timeframe = 60;
 bool repeatKey = false;
 
};

#endif // SETUP_H
