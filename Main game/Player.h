#pragma once
#include "Character.h"

class Player : public Character
{
private:
	int level,expMax,exp;
	// << ����������� ���������

public:
	Player();
	void SetName(std::string name) { this->name = name; }
	void LevelUp();
};


