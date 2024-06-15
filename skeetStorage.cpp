#include "skeetStorage.h"
#include "flyer.h"

BirdFactory SkeetStorage::getBirdFactory()
{
	switch (time.level())
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

void SkeetStorage::enrollPoints(Points* point)
{
    points.push_back(point);
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

void SkeetStorage::unenrollEffect(Effect* effect)
{
    auto it = std::find(effects.begin(), effects.end(), effect);
    if (it != effects.end())
    {
        effects.erase(it);
    }
}

Flyer* BirdFactory::factory(Type type)
{
    return nullptr;
}

Flyer* BirdFactoryLevel1::factory(Type type)
{
    double size = 30.0;
    switch (type)
    {
    case STANDARD:
        Flyer* f = new Flyer(size, 7.0, 12);
        f->setDrawer(new DrawRegular());
        f->setMover(new MoveRegular());
        return f;
    }
}

Flyer* BirdFactoryLevel2::factory(Type type)
{
    int size = 25.0;
    switch (type)
    {
    case STANDARD:
        Flyer* f = new Flyer(size, 7.0, 12);
        f->setDrawer(new DrawRegular());
        f->setMover(new MoveRegular());
        return f;

    case SINKER:
        Flyer* f = new Flyer(size, 7.0, 12);
        f->setDrawer(new DrawSinker());
        f->setMover(new MoveSinker());
        return f;
    }
}

Flyer* BirdFactoryLevel3::factory(Type type)
{
    int size = 20.0;
    switch (type)
    {
    case STANDARD:
        Flyer* f = new Flyer(size, 7.0, 12);
        f->setDrawer(new DrawRegular());
        f->setMover(new MoveRegular());
        return f;

    case SINKER:
        Flyer* f = new Flyer(size, 7.0, 12);
        f->setDrawer(new DrawSinker());
        f->setMover(new MoveSinker());
        return f;

    case FLOATER:
        Flyer* f = new Flyer(size, 7.0, 12);
        f->setDrawer(new DrawFloater());
        f->setMover(new MoveFloater());
        return f;
    }
}

Flyer* BirdFactoryLevel4::factory(Type type)
{
    int size = 15.0;
    switch (type)
    {
    case STANDARD:
        Flyer* f = new Flyer(size, 4.0, 12);
        f->setDrawer(new DrawRegular());
        f->setMover(new MoveRegular());
        return f;

    case SINKER:
        Flyer* f = new Flyer(size, 3.5, 12);
        f->setDrawer(new DrawSinker());
        f->setMover(new MoveSinker());
        return f;

    case FLOATER:
        Flyer* f = new Flyer(size, 4.0, 12);
        f->setDrawer(new DrawFloater());
        f->setMover(new MoveFloater());
        return f;

    case CRAZY:
        Flyer* f = new Flyer(size);
        f->setDrawer(new DrawCrazy());
        f->setMover(new MoveCrazy());
        return f;
    }
}

