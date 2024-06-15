//
//  drawer.hpp
//  Lab03
//
//  Created by Andre Regino Paniagua on 11/06/24.
//

#pragma once
#include "position.h"
#include <stdio.h>
class Flyer;
class Effect;
class Points;

class Drawer
{
public:
   virtual void draw(Position pt, double radius, Velocity v  = Velocity()) = 0;
   virtual void draw(Flyer* flyer) = 0;
   virtual void draw(Effect* effect) = 0;
   virtual void draw(Points* point) = 0;

};

/*************************************
 * BIRD DRAWER is the base class
 * for all the classes to draw different birds
 **************************************/
class BirdDrawer : public Drawer
{
public:
   void drawDisk(const Position& center, double radius, double red, double green, double blue)const;
   virtual void draw(Flyer* flyer) = 0;
};

class DrawRegular : public BirdDrawer
{
public:
   void draw(Flyer* flyer);
};

class DrawFloater : public BirdDrawer
{
public:
   void draw(Flyer* flyer);
};

class DrawSinker : public BirdDrawer
{
public:
   void draw(Flyer* flyer);
};

class DrawCrazy : public BirdDrawer
{
public:
   void draw(Flyer* flyer);
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
   virtual void draw(Flyer* flyer) = 0;
};

class DrawPellet : public BulletDrawer
{
public:
   void draw(Flyer* flyer);
};

class DrawBomb : public BulletDrawer
{
public:
   void draw(Flyer* flyer);
};

class DrawShrapnel : public BulletDrawer
{
public:
   void draw(Flyer* flyer);
};

class DrawMissile : public BulletDrawer
{
public:
   void draw(Flyer* flyer);
};



/*************************************
 * PointDrawer
 **************************************/

class PointDrawer : public Drawer
{
public:
   void draw(Points* point);
};


/*************************************
 * EFFECT DRAWER is the base class
 * for all the classes to draw different effects
 **************************************/

class EffectDrawer : public Drawer
{
public:
  virtual void draw(Effect* effect) = 0;
};

class DrawFragment : public EffectDrawer
{
public:
   void draw(Effect* effect);
};

class DrawStreek : public EffectDrawer
{
public:
   void draw(Effect* effect);
};

class DrawExhaust : public EffectDrawer
{
public:
   void draw(Effect* effect);
};
