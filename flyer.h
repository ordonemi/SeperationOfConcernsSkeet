/***********************************************************************
 * Header File:
 *    Flyer : Anything that moves across the screen
 * Author:
 *    Emilio Ordonez
 * Summary:
 *    Anything that moves accross the screen
 ************************************************************************/

#pragma once
#include "position.h"
// INCLUDE DRAWER AND MOVER HEADER FILES

/******************************************
 * FLYER
 * Anything that can move across the screen.
 *******************************************/
class Flyer
{
private:
	static Position dimensions; // size of the screen
	Position pt;                  // position of the flyer
	Velocity v;                // velocity of the flyer
	double radius;             // the size (radius) of the flyer
	bool dead;                 // is this flyer dead?
	int points;                // how many points is this worth?
	Type type;
	//Drawer drawer;
	//Mover mover;
public:
public:
	Flyer(Type id) : dead(false), points(0), radius(1.0) { type = id; }

	// setters
	void operator=(const Position& rhs) { pt = rhs; }
	void operator=(const Velocity& rhs) { v = rhs; }
	void kill() { dead = true; }
	void setPoints(int pts) { points = pts; }

	// getters
	bool isDead()           const { return dead; }
	Position getPosition()     const { return pt; }
	Velocity getVelocity()  const { return v; }
	double getRadius()      const { return radius; }
	int getPoints() const { return points; }
	Type getType() const { return type; }
	//Drawer& getDrawer() const { return *drawer; }
	//Mover& getMover() const { return *mover; }


	bool isOutOfBounds() const
	{
		return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
			pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
	}
};

enum Type
{
	STANDARD, FLOATER, SINKER, CRAZY;
};