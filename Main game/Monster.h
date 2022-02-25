#pragma once
#include<iostream>
#include "Character.h"
#include"Monster.h"

enum MonsterType
{
	SKELETON,
	ORC,
	LICH,
	DRACON,
	MAX

};

class Monster : public Character
{
public:
	Monster(MonsterType type);

private:



};
