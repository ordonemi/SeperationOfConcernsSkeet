//
//  drawer.hpp
//  Lab03
//
//  Created by Andre Regino Paniagua on 11/06/24.
//

#pragma once
#include "position.h"


#include <stdio.h>

class Drawer
{
public:
   virtual void draw(Position pt, double radius, Velocity v  = Velocity()) = 0;
   virtual void drawEffects(Position pt, Velocity v, double age = 0, double size = 0  ) = 0;
   virtual void drawPoints(Position pt, int value, float age) = 0;


};

/*************************************
 * BIRD DRAWER is the base class
 * for all the classes to draw different birds
 **************************************/
class BirdDrawer : public Drawer
{
public:
   void drawDisk(const Position& center, double radius, double red, double green, double blue)const;
   virtual void draw(Position pt, double radius, Velocity v = Velocity() ) = 0;
};

class DrawRegular : public BirdDrawer
{
public:
   void draw(Position pt, double radius, Velocity v = Velocity() );
};

class DrawFloater : public BirdDrawer
{
public:
   void draw(Position pt, double radius, Velocity v = Velocity() );
};

class DrawSinker : public BirdDrawer
{
public:
   void draw(Position pt, double radius, Velocity v = Velocity() );
};

class DrawCrazy : public BirdDrawer
{
public:
   void draw(Position pt, double radius, Velocity v = Velocity() );
};


/*************************************
 * BULLET DRAWER is the base class
 * for all the classes to draw different bullets
 **************************************/
class BulletDrawer : public Drawer
{
public:
   void drawLine(const Position& begin, const Position& end,double red, double green, double blue) const;
   void drawDot(const Position& point, double radius, double red, double green, double blue) const;
   virtual void draw(Position pt, double radius, Velocity v = Velocity() ) = 0;
};

class DrawPellet : public BulletDrawer
{
public:
   void draw(Position pt, double radius, Velocity v = Velocity() );
};

class DrawBomb : public BulletDrawer
{
public:
   void draw(Position pt, double radius, Velocity v = Velocity() );
};

class DrawShrapnel : public BulletDrawer
{
public:
   void draw(Position pt, double radius, Velocity v = Velocity() );
};

class DrawMissile : public BulletDrawer
{
public:
   void draw(Position pt, double radius, Velocity v = Velocity() );
};



/*************************************
 * PointDrawer
 **************************************/

class PointDrawer : public Drawer
{
public:
   void drawPoints(Position pt, int value, float age);
};


/*************************************
 * EFFECT DRAWER is the base class
 * for all the classes to draw different effects
 **************************************/

class EffectDrawer : public Drawer
{
public:
  virtual void drawEffects(Position pt, Velocity v, double age = 0, double size = 0, Position ptEnd = Position() ) = 0;
};

class DrawFragment : public EffectDrawer
{
public:
   void drawEffects(Position pt, Velocity v, double age = 0, double size = 0, Position ptEnd = Position());
};

class DrawStreek : public EffectDrawer
{
public:
   void drawEffects(Position pt, Velocity v, double age = 0, double size = 0, Position ptEnd = Position());
};

class DrawExhaust : public EffectDrawer
{
public:
   void drawEffects(Position pt, Velocity v, double age = 0, double size = 0, Position ptEnd = Position());
};
