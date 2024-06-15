#pragma once
#include "bird.h"
#include "gun.h"
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
	std::vector<Effect*> effects;
	std::vector<Points*> points;

	Gun      gun;
	Time     time;
	Score    score;
	HitRatio hitRatio;
	Position dimensions;

public:
	void enrollBird  (Flyer* bird);
	void unenrollBird(Flyer*  bird);

	void enrollBullet  (Flyer* bullet);
	void unenrollBullet(Flyer* bullet);

	void enrollEffects(Effect* effect);
	void unenrollPoint(Score* score);

	BirdFactory getBirdFactory();

	std::vector<Flyer*>::iterator getBirdIterator() { return birds.begin(); }
	std::vector<Flyer*>::iterator getBirdEnd() { return birds.end(); }
	std::vector<Flyer*>::iterator getBulletIterator() { return bullets.begin(); }
	std::vector<Flyer*>::iterator getBulletEnd() { return bullets.end(); }
	std::vector<Effect*>::iterator getEffectIterator() { return effects.begin(); }
	std::vector<Effect*>::iterator getEffectEnd() { return effects.end(); }
	std::vector<Points*>::iterator getPointIterator() { return points.begin(); }
	std::vector<Points*>::iterator getPointEnd() { return points.end(); }

	int getLevel() const { return time.level(); }
	int getBirdsSize() { return birds.size(); }
	Gun getGun() { return gun; }
	Position getDimension() const { return dimensions; }
	bool isGameOver() const { return time.isGameOver(); }
	bool isPlaying() const { return time.isPlaying(); }
	double getPercentLeft() const { return time.percentLeft(); }
	double secondsLeft() const { return time.secondsLeft(); }
	std::string getTimeText() const { return time.getText(); }
	std::string getScoreText() const { return score.getText(); }
	std::string getHitRatioText() const { return hitRatio.getText(); }
	void reset()
	{
		time.reset();
		score.reset();
		hitRatio.reset();
	}
};

