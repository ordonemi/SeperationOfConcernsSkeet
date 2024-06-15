/***********************************************************************
 * Header File:
 *    SkeetLogic : Class that holds game logic
 * Author:
 *    Emilio Ordonez
 * Summary:
 *    Handles moving components of game
 ************************************************************************/

#pragma once
#include "skeetStorage.h"

class SkeetLogic
{
public:
	void move();
	void animate(); // Flyer& it
	void spawn();
	void fire(Flyer* p);
private:
	SkeetStorage storage;

	void advanceTime() { storage.advanceTime(); }
	bool isStatus() { storage.isStatus(); }
	void clearBirds() { storage.clearBirds(); }
	void clearBullets() { storage.clearBullets(); }
	void clearEffects() { storage.clearEffects(); }
	void clearPoints() { storage.clearPoints(); }
	void death() { storage.death() }
};
