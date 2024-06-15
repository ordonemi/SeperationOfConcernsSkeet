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
	for (auto it = storage.getBirdIterator(); it != storage.getBirdEnd(); ++it) {
		(*it)->getMover()->move();
	}

	for (auto it = storage.getBulletIterator(); it != storage.getBulletEnd(); ++it) {
		(*it)->getMover()->move();
	}

	for (auto it = storage.getEffectIterator(); it != storage.getEffectEnd(); ++it) {
		(*it)->getMover()->move();
	}

	for (auto it = storage.getPointIterator(); it != storage.getPointEnd(); ++it) {
		(*it)->getMover()->move();
	}
}

/******************************************************
 * SKEETLOGIC : ANIMATE
 * Perform hit detection on the components of the game?
 ******************************************************/
void SkeetLogic::animate()
{
}

///************************
// * SKEET ANIMATE
// * move the gameplay by one unit of time
// ************************/
//void Skeet::animate()
//{
//   time++;
//   
//   // if status, then do not move the game
//   if (time.isStatus())
//   {
//      // get rid of the bullets and the birds without changing the score
//      birds.clear();
//      bullets.clear();
//      effects.clear();
//      points.clear();
//      return;
//   }
//   
//   // spawn
//   spawn();
//   
//   // move the birds and the bullets
//   for (auto element : birds)
//   {
//      element->advance();
//      hitRatio.adjust(element->isDead() ? -1 : 0);
//   }
//   for (auto bullet : bullets)
//      bullet->move(effects);
//   for (auto effect : effects)
//      effect->fly();
//   for (auto & pts : points)
//      pts.update();
//      
//   // hit detection
//   for (auto element : birds)
//      for (auto bullet : bullets)
//         if (!element->isDead() && !bullet->isDead() &&
//             element->getRadius() + bullet->getRadius() >
//             minimumDistance(element->getPosition(), element->getVelocity(),
//                             bullet->getPosition(),  bullet->getVelocity()))
//         {
//            for (int i = 0; i < 25; i++)
//               effects.push_back(new Fragment(bullet->getPosition(), bullet->getVelocity()));
//            element->kill();
//            bullet->kill();
//            hitRatio.adjust(1);
//            bullet->setValue(-(element->getPoints()));
//            element->setPoints(0);
//         }
//   
//   // remove the zombie birds
//   for (auto it = birds.begin(); it != birds.end();)
//      if ((*it)->isDead())
//      {
//         if ((*it)->getPoints())
//            points.push_back(Points((*it)->getPosition(), (*it)->getPoints()));
//         score.adjust((*it)->getPoints());
//         it = birds.erase(it);
//      }
//      else
//         ++it;
//       
//   // remove zombie bullets
//   for (auto it = bullets.begin(); it != bullets.end(); )
//      if ((*it)->isDead())
//      {
//         (*it)->death(bullets);
//         int value = -(*it)->getValue();
//         points.push_back(Points((*it)->getPosition(), value));
//         score.adjust(value);
//         it = bullets.erase(it);
//      }
//      else
//         ++it;
//   
//   // remove zombie fragments
//   for (auto it = effects.begin(); it != effects.end();)
//      if ((*it)->isDead())
//         it = effects.erase(it);
//      else
//         ++it;
//
//   // remove expired points
//   for (auto it = points.begin(); it != points.end();)
//      if ((*it).isDead())
//         it = points.erase(it);
//      else
//         ++it;
//}

/******************************************
 * SKEETLOGIC : SPAWN
 * Spawn new birds and add them to storage
 ******************************************/
void SkeetLogic::spawn()
{
	switch (storage.getLevel())
	{
	// level 1 only has standard birds
	case 1:
		if (storage.getBirdsSize() == 0 && random(0, 15) == 1)
			storage.enrollBird(storage.getBirdFactory().factory(STANDARD));
		if (random(0, 4 * 30) == 1)
			storage.enrollBird(storage.getBirdFactory().factory(STANDARD));
		break;

	// Level 2 has standard and sinker bird
	case 2:
		if (storage.getBirdsSize() == 0 && random(0, 15) == 1)
			storage.enrollBird(storage.getBirdFactory().factory(STANDARD));
		if (random(0, 4 * 30) == 1)
			storage.enrollBird(storage.getBirdFactory().factory(STANDARD));
		if (random(0, 4 * 30) == 1)
			storage.enrollBird(storage.getBirdFactory().factory(SINKER));
		break;

	// level 3 has standard, sinker and floater
	case 3:
		if (storage.getBirdsSize() == 0 && random(0, 15) == 1)
			storage.enrollBird(storage.getBirdFactory().factory(STANDARD));
		if (random(0, 4 * 30) == 1)
			storage.enrollBird(storage.getBirdFactory().factory(STANDARD));
		if (random(0, 4 * 30) == 1)
			storage.enrollBird(storage.getBirdFactory().factory(SINKER));
		if (random(0, 4 * 30) == 1)
			storage.enrollBird(storage.getBirdFactory().factory(FLOATER));
		break;

	// level 4 has standard, sinker, floater, and crazy bird
	case 4:
		if (storage.getBirdsSize() == 0 && random(0, 15) == 1)
			storage.enrollBird(storage.getBirdFactory().factory(STANDARD));
		if (random(0, 4 * 30) == 1)
			storage.enrollBird(storage.getBirdFactory().factory(STANDARD));
		if (random(0, 4 * 30) == 1)
			storage.enrollBird(storage.getBirdFactory().factory(SINKER));
		if (random(0, 4 * 30) == 1)
			storage.enrollBird(storage.getBirdFactory().factory(FLOATER));
		if (random(0, 4 * 30) == 1)
			storage.enrollBird(storage.getBirdFactory().factory(CRAZY));
		break;
	default:
		break;
	}
}

/*****************************************
 * SKEETLOGIC : FIRE 
 * Fire a bullet 
 *****************************************/
void SkeetLogic::fire(Flyer* p)
{
	storage.enrollBullet(p);
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