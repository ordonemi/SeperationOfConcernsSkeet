#include "skeetStorage.h"

BirdFactory SkeetStorage::getBirdFactory()
{
	switch (time->level())
	{
	case 1:
		return birdFactoryL1;

	case 2:
		return birdFactoryL2;

	case 3:
		return birdFactoryL3;

	case 4:
		return birdFactoryL4;
	}
}

void SkeetStorage::enrollBird(Flyer* bird)
{
	birds.push_back(bird);
}

void SkeetStorage::enrollBullet(Flyer* bullet)
{
	bullets.push_back(bullet);
}

void SkeetStorage::enrollEffects(Effect* effect)
{
	effects.push_back(effect);
}

void SkeetStorage::unenrollBird(Flyer* bird)
{
	auto it = std::find(birds.begin(), birds.end(), bird);
	if (it != birds.end())
	{
		birds.erase(it);
	}
}

void SkeetStorage::unenrollBullet(Flyer* Bullet)
{
	auto it = std::find(bullets.begin(), bullets.end(), bullets);
	if (it != bullets.end())
	{
		bullets.erase(it);
	}
}

void SkeetStorage::unenrollPoint(Score* score)
{
	auto it = std::find(points.begin(), points.end(), points);
	if (it != points.end())
	{
		points.erase(it);
	}
}