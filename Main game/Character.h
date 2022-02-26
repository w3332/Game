#pragma once
#include<iostream>

class Character
{
protected:
	int health, damage, defence;
	std::string name;

public:
	bool CheckLife();
	int DamageToCharacter(Character&unit);
	void DealDamage(int totalDamage);

};


