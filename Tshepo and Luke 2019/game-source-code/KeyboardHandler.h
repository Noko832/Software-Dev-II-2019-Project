#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H
/**
 * @class KeyboardHandler
 * @author Tshepo Monene and Goitseona Mohajane
 * @date 26/09/2019
 * @file KeyboardHandler.h
 * @brief 
 */
#include <SFML/Window.hpp>
#include "Types.h"
class KeyboardHandler
{
public:
/**
 * @brief get an enumarated Key(DIRECTION).
 * @return enumarated Key(DIRECTION).
 */
    DIRECTION getDirection();
/**
 * @brief get an enumarated Key(INSTRUCTION).
 * @return enumarated Key(INSTRUCTION).
 */
    INSTRUCTION getInstruction();

private :
 INSTRUCTION instruction; 
 DIRECTION direction;
 

};

#endif // KEYBOARDHANDLER_H
