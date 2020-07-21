#include "Setup.h"

int Setup::getWidth() 
{
    return width;
}
int Setup::getHeight()
{
    return height;
}
int  Setup::getTimeframe()
{
    return timeframe;
}
bool Setup::keyHandler()
{
    return repeatKey;
}