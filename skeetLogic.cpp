/***********************************************************************
 * Source File:
 *    SkeetLogic
 * Author:
 *    Emilio Ordonez
 * Summary:
 *    Handles moving the different components of the game
 ************************************************************************/

#include "skeetLogic.h"
#include <cassert>
#include <stdlib.h>
using namespace std;

/*****************************************
 * SKEETLOGIC : MOVE
 * Move the components of the game
 ****************************************/
void SkeetLogic::move()
{
	//for (auto it = storage.getBirdIterator(); it != storage.getBirdEnd(); ++it) {
	//	it->getMover()->move();
	//}

	//for (auto it = storage.getBulletIterator(); it != storage.getBulletEnd(); ++it) {
	//	it->getMover()->move();
	//}

	//for (auto it = storage.getEffectIterator(); it != storage.getEffectEnd(); ++it) {
	//	it->getMover()->move();
	//}

	//for (auto it = storage.getPointIterator(); it != storage.getPointEnd(); ++it) {
	//	it->getMover()->move();
	//}
}

/******************************************************
 * SKEETLOGIC : ANIMATE
 * Perform hit detection on the components of the game?
 ******************************************************/
void SkeetLogic::animate()
{
	//
	move();
}

/******************************************
 * SKEETLOGIC : SPAWN
 * Spawn new birds and add them to storage
 ******************************************/
void SkeetLogic::spawn()
{
	//switch (storage.getLevel())
	//{
	//// level 1 only has standard birds
	//case 1:
	//	if (storage.getBirdsSize() == 0 && random(0, 15) == 1)
	//		storage.enrollBird(storage.getBirdFactory()->factory(STANDARD));
	//	if (random(0, 4 * 30) == 1)
	//		storage.enrollBird(storage.getBirdFactory()->factory(STANDARD));
	//	break;

	//// Level 2 has standard and sinker bird
	//case 2:
	//	if (storage.getBirdsSize() == 0 && random(0, 15) == 1)
	//		storage.enrollBird(storage.getBirdFactory()->factory(STANDARD));
	//	if (random(0, 4 * 30) == 1)
	//		storage.enrollBird(storage.getBirdFactory()->factory(STANDARD));
	//	if (random(0, 4 * 30) == 1)
	//		storage.enrollBird(storage.getBirdFactory()->factory(SINKER));
	//	break;

	//// level 3 has standard, sinker and floater
	//case 3:
	//	if (storage.getBirdsSize() == 0 && random(0, 15) == 1)
	//		storage.enrollBird(storage.getBirdFactory()->factory(STANDARD));
	//	if (random(0, 4 * 30) == 1)
	//		storage.enrollBird(storage.getBirdFactory()->factory(STANDARD));
	//	if (random(0, 4 * 30) == 1)
	//		storage.enrollBird(storage.getBirdFactory()->factory(SINKER));
	//	if (random(0, 4 * 30) == 1)
	//		storage.enrollBird(storage.getBirdFactory()->factory(FLOATER));
	//	break;

	//// level 4 has standard, sinker, floater, and crazy bird
	//case 4:
	//	if (storage.getBirdsSize() == 0 && random(0, 15) == 1)
	//		storage.enrollBird(storage.getBirdFactory()->factory(STANDARD));
	//	if (random(0, 4 * 30) == 1)
	//		storage.enrollBird(storage.getBirdFactory()->factory(STANDARD));
	//	if (random(0, 4 * 30) == 1)
	//		storage.enrollBird(storage.getBirdFactory()->factory(SINKER));
	//	if (random(0, 4 * 30) == 1)
	//		storage.enrollBird(storage.getBirdFactory()->factory(FLOATER));
	//	if (random(0, 4 * 30) == 1)
	//		storage.enrollBird(storage.getBirdFactory()->factory(CRAZY));
	//	break;
	//default:
	//	break;
	//}
}

/*****************************************
 * SKEETLOGIC : FIRE 
 * Fire a bullet 
 *****************************************/
void SkeetLogic::fire()
{
	//storage.enrollBullet(new Bullet());
}

/******************************************************************
 * RANDOM
 * This function generates a random number.
 *
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer
 ****************************************************************/
int random(int min, int max)
{
	assert(min < max);
	int num = (rand() % (max - min)) + min;
	assert(min <= num && num <= max);

	return num;
}