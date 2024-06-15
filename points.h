/***********************************************************************
 * Header File:
 *    Points : Points graphic drawn on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Inert point values on the screen.
 ************************************************************************/


#pragma once

#include "position.h"
#include "drawer.h"
#include "mover.h"

 /*********************************************
  * POINTS
  * Points graphic drawn on the screen
  *********************************************/
class Points
{
public:
   Points(const Position& pt, int value);
   PointDrawer* drawer;
   PointMover* mover;
   void update();
   bool isDead() const {return age <= 0.0; }

   PointDrawer* getDrawer()
   {
	   return drawer;
   }

   PointMover* getMover() { return mover; }
   Velocity& getVelocity(){ return v;     }

   Position getPosition() { return pt; }
   int getValue() { return value; }
   float& getAge() { return age; }
private:
   Position pt;
   Velocity v;
   int value;
   float age;
};
