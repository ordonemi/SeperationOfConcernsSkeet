/***********************************************************************
 * Source File:
 *    SkeetLogic
 * Author:
 *    Emilio Ordonez
 * Summary:
 *    Handles moving the different components of the game
 ************************************************************************/

#include "skeetLogic.h"
#include "flyer.h"
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

/************************
 * SKEET ANIMATE
 * move the gameplay by one unit of time
 ************************/
void SkeetLogic::animate()
{
	advanceTime();
   
   // if status, then do not move the game
   if (isStatus())
   {
      // get rid of the bullets and the birds without changing the score
	   clearBirds();
	   clearBullets();
	   clearEffects();
	   clearPoints();
       return;
   }
   
   // spawn
   spawn();
   
   // move the birds and the bullets
   move();
      
   // hit detection
   for (auto bird = storage.getBirdIterator(); bird != storage.getBirdEnd(); ++bird)
	   for (auto bullet = storage.getBulletIterator(); bullet != storage.getBulletEnd(); ++bullet)
         if (!(*bird)->isDead() && !(*bullet)->isDead() &&
             (*bird)->getRadius() + (*bullet)->getRadius() >
             minimumDistance((*bird)->getPosition(), (*bird)->getVelocity(),
                             (*bullet)->getPosition(),  (*bullet)->getVelocity()))
         {
			for (int i = 0; i < 25; i++)
			{
				Fragment* f = new Fragment((*bullet)->getPosition(), (*bullet)->getVelocity());
				storage.enrollEffects(f);
			}
            (*bird)->kill();
            (*bullet)->kill();
			storage.getHitRatio().adjust(1);
            (*bullet)->setPoints(-(*bird)->getPoints()));
            (*bird)->setPoints(0);
         }
   
   // remove the zombie birds
   for (auto bird = storage.getBirdIterator(); bird != storage.getBirdEnd(); ++bird)
      if ((*bird)->isDead())
      {
		 if ((*bird)->getPoints())
		 {
			 Points* p = new Points((*bird)->getPosition(), (*bird)->getPoints());
			 storage.enrollPoints(p);
		 }
		 storage.getScore().adjust((*bird)->getPoints());
		 storage.unenrollBird((*bird));
      }
      else
         ++bird;
       
   // remove zombie bullets
   for (auto bullet = storage.getBulletIterator(); bullet != storage.getBulletEnd(); ++bullet)
      if ((*bullet)->isDead())
      {
		  if ((*bullet)->getType() == BOMB)
		  {
			  for (int i = 0; i < 20; i++)
			  {
				  Flyer* shrapnel = new Flyer();
				  shrapnel->setDrawer(new DrawShrapnel);
				  shrapnel->setMover(new MoveShrapnel);
				  storage.enrollBullet(shrapnel);
			  }
		  }
         int value = -(*bullet)->getPoints();
		 storage.enrollPoints(new Points((*bullet)->getPosition(), value));
		 storage.getScore().adjust(value);
		 storage.unenrollBullet((*bullet));
      }
      else
         ++bullet;
   
   // remove zombie fragments
   for (auto it = storage.getEffectIterator(); it != storage.getEffectEnd(); ++it)
	  if ((*it)->isDead())
		  storage.unenrollEffect((*it));
      else
         ++it;

   // remove expired points
   for (auto it = storage.getPointIterator(); it != storage.getPointEnd(); ++it)
	  if ((*it)->isDead())
		  storage.unenrollPoint((*it));
      else
         ++it;
}

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