#pragma once
#include "Character.h"
#include "Buff.h"

class Player : public Character
{
private:
	int level, exp ,expMax;
public:
	Player();
	
	// увеличивает опыт
	void Experience(int expr);

	void SetName (std::string name) { this->name = name; }
	int GetLevel() { return level;}

};



