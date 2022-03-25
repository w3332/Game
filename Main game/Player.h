#pragma once
#include <map>

#include "Character.h"
#include "Function.h"

class Player : public Character
{
private:
	int level, exp ,expMax;
	std::map<std::string, int> backpack;
public:
	Player();
	
	// увеличивает опыта
	void Experience(int expr);

	// положить что то в инвентарь
	void PutInBackpack(std::string itemname);

	// посмотреть инвентарь
	void LookInBackpack();

	void SetName (std::string name) { this->name = name; }
	int GetLevel() { return level;}

};



