#pragma once
#include "Character.h"

enum MonsterType
{
	SKELETON,
	ORC,
	LICH,
	DRAGON,
	MAX
};

class Monster : public Character
{
private:

public:
	Monster(MonsterType type);
};
