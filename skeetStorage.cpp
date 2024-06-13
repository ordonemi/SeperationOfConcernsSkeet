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