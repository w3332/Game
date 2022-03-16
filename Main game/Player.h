#pragma once
#include "Character.h"
#include "Monster.h"

class Player : public Character
{
private:
	int level,expMax,exp;
	// << реализовать инвентарь

public:
	Player();
	void SetName(std::string name) { this->name = name; }
	void LevelUp(MonsterType type);
	int GetLevel() {
		return level;
	}
};



