//
//  mover.hpp
//  Lab03
//
//  Created by Andre Regino Paniagua on 13/06/24.
//
#pragma once

#include "position.h"


#include <stdio.h>

class Flyer;

class Mover
{
public:
   virtual void move(Position & pt, double radius, Velocity &v, Position dimensions ) = 0;
   virtual void moveFlyer(Flyer *flyer) = 0;
   bool isOutOfBounds(Flyer *flyer)const;
   double randomFloat(double min, double max);
   int randomInt(int min, int max);
};

/*************************************
 * BIRD DRAWER is the base class
 * for all the classes to move different birds
 **************************************/
class BirdMover : public Mover
{
public:
   virtual void moveFlyer(Flyer *flyer) = 0;
};

class MoveRegular : public BirdMover
{
public:
   void moveFlyer(Flyer *flyer);
};

class MoveFloater : public BirdMover
{
public:
   void moveFlyer(Flyer *flyer);
};

class MoveSinker : public BirdMover
{
public:
   void moveFlyer(Flyer *flyer);
};

class MoveCrazy : public BirdMover
{
public:
   void moveFlyer(Flyer *flyer);
};


/*************************************
 * BULLET DRAWER is the base class
 * for all the classes to move different bullets
 **************************************/
class BulletMover : public Mover
{
public:
   virtual void move(Position pt, double radius, Velocity v ) = 0;
};

class MovePellet : public BulletMover
{
public:
   void move(Position pt, double radius, Velocity v );
};

class MoveBomb : public BulletMover
{
public:
   void move(Position pt, double radius, Velocity v );
};

class MoveShrapnel : public BulletMover
{
public:
   void move(Position pt, double radius, Velocity v );
};

class MoveMissile : public BulletMover
{
public:
   void move(Position pt, double radius, Velocity v );
};


class PointMover : public Mover
{
public:
   void move(Position pt, double radius, Velocity v );
};

class EffectMover : public Mover
{
public:
   void move(Position pt, double radius, Velocity v );
};



