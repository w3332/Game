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
	MonsterType thisMonster;

public:
	Monster(MonsterType type);
	MonsterType GetType() {
		return thisMonster;
	}
};
