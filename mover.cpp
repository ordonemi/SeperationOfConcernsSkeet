//
//  mover.cpp
//  Lab03
//
//  Created by Andre Regino Paniagua on 13/06/24.
//

#include "mover.h"
#include <cassert>
#include "flyer.h"
#include "skeetStorage.h"
#include "effect.h"
#include "points.h"


/******************************************************************
 * RANDOM
 * These functions generate a random number.
 ****************************************************************/
int Mover::randomInt(int min, int max)
{
   assert(min < max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);
   return num;
}
double Mover::randomFloat(double min, double max)
{
   assert(min <= max);
   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
   assert(min <= num && num <= max);
   return num;
}

bool Mover::isOutOfBounds(Flyer *flyer)const
{
   return (flyer->getPosition().getX() < -flyer->getRadius() || flyer->getPosition().getX() >= flyer->getDimension().getX() + flyer->getRadius() ||
           flyer->getPosition().getY() < -flyer->getRadius() || flyer->getDimension().getY() >= flyer->getDimension().getY() + flyer->getRadius());
}

/***************************************************************/
/***************************************************************/
/*            BULLET MOVER               */
/***************************************************************/
/***************************************************************/

void BulletMover :: move(Flyer *flyer)
{
   // inertia
   flyer->getPosition().add(flyer->getVelocity());

   // out of bounds checker
   if (isOutOfBounds(flyer))
      flyer->kill();
}

void MovePellet ::move(Flyer *flyer)
{
   BulletMover :: move(flyer);
};

void MoveBomb :: move(Flyer *flyer)
{
   // kill if it has been around too long
   flyer->lowerTimeToDie();
   if (!flyer->getTimeToDie())
       flyer->kill();
   
   BulletMover::move(flyer);
   
};

void MoveShrapnel :: move(Flyer *flyer)
{
   // kill if it has been around too long
   flyer->lowerTimeToDie();
   if (!flyer->getTimeToDie())
       flyer->kill();

   // add a streek
   storage->enrollEffects(new Streek (flyer->getPosition(), flyer->getVelocity()));
   
   // do the usual bullet stuff (like inertia)
   BulletMover::move(flyer);
};

void MoveMissile :: move(Flyer *flyer)
{
   // add an exhoust
   storage->enrollEffects(new Exhaust (flyer->getPosition(), flyer->getVelocity()));
   // do the usual bullet stuff (like inertia)
   BulletMover::move(flyer);
};

/***************************************************************/
/***************************************************************/
/*            POINT MOVER                */
/***************************************************************/
/***************************************************************/


void PointMover :: move(Points *point)
{
   point->getVelocity().addDx(randomFloat(-0.15, 0.15));
   point->getVelocity().addDy(randomFloat(-0.15, 0.15));
   point->getPosition() += point->getVelocity();
   point->getAge() -= 0.01;
};

/***************************************************************/
/***************************************************************/
/*            EFFECT MOVER                */
/***************************************************************/
/***************************************************************/

void MoveStreek :: move(Effect *effect)
{
   // move it forward with inertia (no gravity)
//    pt += v;
   
  // increase the age so it fades away
   effect->updateAge(0.10);
};

void MoveFragment :: move(Effect *effect)
{
   Fragment * fragment = dynamic_cast<Fragment*>(effect);
   // move it forward with inertia (no gravity)
   fragment->updatePosition(fragment->getVelocity());
   
   // increase the age so it fades away
   effect->updateAge(0.02);
   fragment->increaseSize(0.95);
};

void MoveExhaust ::move(Effect *effect)
{
   // move it forward with inertia (no gravity)
//   pt += v;
    
   // increase the age so it fades away
   effect->updateAge(0.025);
};

/***************************************************************/
/***************************************************************/
/*            BIRD MOVER                 */
/***************************************************************/
/***************************************************************/

void MoveRegular :: move(Flyer *flyer)
{
   // small amount of drag
   flyer->getVelocity() *= 0.995;

   // inertia
   flyer->getPosition().add(flyer->getVelocity());

   // out of bounds checker
   if (isOutOfBounds(flyer))
   {
      flyer->kill();
      flyer->updatePoints(-1); // points go negative when it is missed!
   }
};

void MoveFloater :: move(Flyer *flyer)
{
   // large amount of drag
   flyer->getVelocity() *= 0.990;

   // inertia
   flyer->getPosition().add(flyer->getVelocity());

   // anti-gravity
   flyer->getVelocity().addDy(0.05);

   // out of bounds checker
   if (isOutOfBounds(flyer))
   {
      flyer->kill();
      flyer->updatePoints(-1); // points go negative when it is missed!
   }
};

void MoveSinker :: move(Flyer *flyer)
{
   // gravity
   flyer->getVelocity().addDy(-0.07);

   // inertia
   flyer->getPosition().add(flyer->getVelocity());

   // out of bounds checker
   if (isOutOfBounds(flyer))
   {
      flyer->kill();
      flyer->updatePoints(-1); // points go negative when it is missed!
   }
};

void MoveCrazy :: move(Flyer *flyer)
{
   // erratic turns eery half a second or so
   if (randomInt(0, 15) == 0)
   {
      flyer->getVelocity().addDy(randomFloat(-1.5, 1.5));
      flyer->getVelocity().addDx(randomFloat(-1.5, 1.5));
   }

   // inertia
   flyer->getPosition().add(flyer->getVelocity());

   // out of bounds checker
   if (isOutOfBounds(flyer))
   {
      flyer->kill();
      flyer->updatePoints(-1); // points go negative when it is missed!
   }
};
