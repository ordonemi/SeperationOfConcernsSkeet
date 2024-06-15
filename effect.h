/***********************************************************************
 * Header File:
 *    Fragment : Pieces that fly off a dead bird
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Pieces that fly off a dead bird
 ************************************************************************/

#pragma once
#include "position.h"

class Drawer;
class Mover;

/**********************
 * Effect: stuff that is not interactive
 **********************/
class Effect
{
protected:
    Position pt;      // location of the effect
    double age;    // 1.0 = new, 0.0 = dead
    Drawer* drawer;
    Mover* mover;
public:
    // create a fragment based on the velocity and position of the bullet
    Effect(const Position & pt) : pt(pt), age(0.5) {}
    
    // draw it
    virtual void render() const = 0;
    
    // move it forward with regards to inertia. Let it age
    virtual void fly() = 0;
    
    // it is dead when age goes to 0.0
    bool isDead() const { return age <= 0.0; }

    Drawer* getDrawer() { return drawer; }
    Mover* getMover() { return mover; }
    double getAge()     {return age;}
    Position getPosition() {return pt;}
   
    void setPosition(Position pos) { pt = pos; }
    
    
    void updatePosition(Velocity v) { pt += v;}
    void updateAge(float n) { age -= n;}


};

/**********************
 * FRAGMENT
 * Pieces that fly off a dead bird
 **********************/
class Fragment : public Effect
{
private:
   Velocity v;    // direction the fragment is flying
   double size;   // size of the fragment
public:
   // create a fragment based on the velocity and position of the bullet
   Fragment(const Position & pt, const Velocity & v);
   
   // draw it
   void render() const;
   
   // move it forward with regards to inertia. Let it age
   void fly();
   void setVelocity();
   
   double getSize() { return size;}
   Velocity getVelocity() const{ return v;};
   void increaseSize(double n) { size *= n;};
};
/**********************
 * STREEK
 * Stuff that trails off the back of shrapnel
 **********************/
class Streek : public Effect
{
private:
   Position ptEnd;
public:
    // create a fragment based on the velocity and position of the bullet
    Streek(const Position & pt, Velocity v);
    
    // draw it
    void render() const;
    
    // move it forward with regards to inertia. Let it age
    void fly();
   
    Position getPtEnd() { return ptEnd;}
};

/**********************
 * EXHAUST
 * Stuff that comes out the back of a missile when in flight
 **********************/
class Exhaust : public Effect
{
private:
   Position ptEnd;
public:
    // create a fragment based on the velocity and position of the bullet
    Exhaust(const Position & pt, Velocity v);
    
    // draw it
    void render() const;
    
    // move it forward with regards to inertia. Let it age
    void fly();
 
    Position getPtEnd() { return ptEnd;}
};
