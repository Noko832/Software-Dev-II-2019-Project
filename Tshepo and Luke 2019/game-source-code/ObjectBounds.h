#ifndef OBJECTBOUNDS_H
#define OBJECTBOUNDS_H
/**
 * @class ObjectBounds
 * @author Tshepo Monene and Goitseona Mohajane
 * @date 26/09/2019
 * @file ObjectBounds.h
 * @brief 
 */
#include "Types.h"
class ObjectBounds
{
public:
  /**
   * @brief gets the bounds of each entity
   * @param identifier is the idenetifier used to identify the entity.
   * @return dimensions is a 2D struct of float(width, height).
   */
  dimensions getBounds(IDENTIFIER identifier);
 ~ObjectBounds();
 
private:

    dimensions bounds;
};

#endif // OBJECTBOUNDS_H
