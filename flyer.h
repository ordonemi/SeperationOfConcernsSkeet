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
#include "drawer.h"
#include "mover.h"
// INCLUDE DRAWER AND MOVER HEADER FILES

/******************************************
 * FLYER
 * Anything that can move across the screen.
 *******************************************/
class Flyer
{
private:
	static Position dimensions; // size of the screen
	Position pt;                // position of the flyer
	Velocity v;                 // velocity of the flyer
	double radius;              // the size (radius) of the flyer
	bool dead;                  // is this flyer dead?
	int points;                 // how many points is this worth?
	Type type;
	Drawer* drawer;
	Mover* mover;
public:
public:
	Flyer() : dead(false), points(0), radius(1.0), drawer(nullptr), mover(nullptr), type(BULLET) {}
	Flyer(Type id) : dead(false), points(0), radius(1.0), drawer(nullptr), mover(nullptr) { type = id; }
	void setInitial(double angle = 0.0, double speed = 30.0, double radius = 5.0, int value = 1)
	{
		// set the initial position
		pt.setX(dimensions.getX() - 1.0);
		pt.setY(1.0);
		assert(pt.getX() > 100.0);

		// set the initial velocity
		v.setDx(-speed * cos(angle));
		v.setDy(speed * sin(angle));
		assert(v.getDx() <= 0.0);
		assert(v.getDy() >= 0.0);
	}

	// setters
	void operator=(const Position& rhs) { pt = rhs; }
	void operator=(const Velocity& rhs) { v = rhs; }
	void kill() { dead = true; }
	void setPoints(int pts) { points = pts; }
	void setDrawer(Drawer* d) { drawer = d; }
	void setMover(Mover* m) { mover = m; }

	// getters
	bool isDead()           const { return dead; }
	Position getPosition()     const { return pt; }
	Velocity getVelocity()  const { return v; }
	double getRadius()      const { return radius; }
	int getPoints() const { return points; }
	Type getType() const { return type; }
	Drawer* getDrawer() const { return drawer; }
	Mover* getMover() const { return mover; }
	Position getDimension() const { return dimensions;  }

	bool isDead()            { return dead;       }
	Position getPosition()   { return pt;         }
	Velocity getVelocity()   { return v;          }
	double getRadius()       { return radius;     }
	int getPoints()          { return points;     }
	Type getType()           { return type;       }
	Drawer* getDrawer()      { return drawer;     }
	Mover* getMover()        { return mover;      }
	Position getDimension()  { return dimensions; }


	bool isOutOfBounds() const
	{
		return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
			pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
	}
};

enum Type
{
	STANDARD, FLOATER, SINKER, CRAZY, BULLET, MISSILE
};