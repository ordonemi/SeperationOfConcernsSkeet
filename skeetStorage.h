#pragma once
#include "bird.h"
#include "gun.h"
#include "bullet.h"
#include "effect.h"
#include "time.h"
#include "score.h"
#include "points.h"
#include "vector"

class Flyer;
class SkeetStorage
{
private:
	BirdFactoryLevel1 birdFactoryL1;
	BirdFactoryLevel2 birdFactoryL2;
	BirdFactoryLevel3 birdFactoryL3;
	BirdFactoryLevel4 birdFactoryL4;

	std::vector<Flyer*> birds;
	std::vector<Flyer*> bullets;
	std::vector<Effect> effects;
	std::vector<Points> points;
	std::vector<BirdFactory> levels;

	Bird*     bird;
	Gun*      gun;
	Time*     time;
	Score*    score;
	HitRatio* hitRatio;

public:
	void enrollBird  (Flyer* bird);
	void unenrollBird(Flyer* bird);

	void enrollBullet  (Bullet bullet);
	void unenrollBullet(Bullet bullet);

	void enrollEffects(Effect effect);
	void unenrollPoint(Score score);

	void getBirdIterator();
	void getBulletIterator();
	void getEffectIterator();
	void getPointIterator();

	BirdFactory getBirdFactory();
};

