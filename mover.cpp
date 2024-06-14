//
//  mover.cpp
//  Lab03
//
//  Created by Andre Regino Paniagua on 13/06/24.
//

#include "mover.h"
#include <cassert>
#include "flyer.h"

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


void MovePellet ::move(Position pt, double radius, Velocity v )
{
};

void MoveBomb :: move(Position pt, double radius, Velocity v )
{
};

void MoveShrapnel :: move(Position pt, double radius, Velocity v )
{
};

void MoveMissile :: move(Position pt, double radius, Velocity v )
{
};


void PointMover :: move(Position pt, double radius, Velocity v )
{
};

void EffectMover :: move(Position pt, double radius, Velocity v )
{
};


void MoveRegular :: moveFlyer(Flyer *flyer)
{
   // small amount of drag
   flyer->getVelocity() *= 0.995;

   // inertia
   flyer->getPosition().add(flyer->getVelocity());

   // out of bounds checker
   if (isOutOfBounds(flyer))
   {
      flyer->kill();
      flyer->getPoints() *= -1; // points go negative when it is missed!
   }
};

void MoveFloater :: moveFlyer(Flyer *flyer)
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
      flyer->getPoints() *= -1; // points go negative when it is missed!
   }
};

void MoveSinker :: moveFlyer(Flyer *flyer)
{
   // gravity
   flyer->getVelocity().addDy(-0.07);

   // inertia
   flyer->getPosition().add(flyer->getVelocity());

   // out of bounds checker
   if (isOutOfBounds(flyer))
   {
      flyer->kill();
      flyer->getPoints() *= -1; // points go negative when it is missed!
   }
};

void MoveCrazy :: moveFlyer(Flyer *flyer)
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
      flyer->getPoints() *= -1; // points go negative when it is missed!
   }
};
