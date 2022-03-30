#pragma once
#include "Character.h"

enum MonsterType
{
	SKELETON,
	ORC,
	LICH,
	DRAGON,
	BOSS,
	MAXMON
};

class Monster : public Character
{
private:
	MonsterType thisMonster;

public:
	Monster(MonsterType type);

	MonsterType GetType() { return thisMonster; }

	// возвращает кол-во опыта в зависимости от типа монстра
	int GetExperience();

	// возвращает рандомный тип монстра
	static MonsterType SelectMonster(int level);
};
