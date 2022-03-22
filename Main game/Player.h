#pragma once
#include <vector>
#include "Character.h"
#include "Monster.h"

class Player : public Character
{
private:
	int level,expMax,exp;
	//std::vector <Item> inventory;

public:
	Player();
	void SetName(std::string name) { this->name = name; }
	void LevelUp(MonsterType type);

	int GetLevel() {return level;}

	/*void AddToInventory(Item &item)	{inventory.push_back(item);}
	void UsePotion(int value) {
		health += value;
	}
	void LookInventory()
	{
		for (Item var : inventory)
		{
			cout << var.GetName()<<endl;


		}
	}*/
};



