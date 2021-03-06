#include "Character.h"

Character::Character()
{
	this->xPos = 0.0;
	this->yPos = 0.0;

	this->name = "";
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;

	this->statPoints = 0;
	this->skillPoints = 0;

	this->strength = 2;
	this->stealth = 2;
	this->magic = 2;
	this->hacking = 2;
	this->vitality = 2;

	this->hp = 0;
	this->hpMax = 0;
	this->stamina = 0;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->luck = 0;
}


Character::~Character()
{
}

//functions

void Character::initliaze(const std::string name)
{
	this->xPos = 0.0;
	this->yPos = 0.0;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = 
		static_cast<int>((50 / 3)*((pow(level, 3)
			- 6 * pow(level, 2))
			+ 17 * level - 12)) + 100;

	this->statPoints = 0;
	this->skillPoints = 0;

	this->strength = 2;
	this->stealth = 2;
	this->magic = 2;
	this->hacking = 2;
	this->vitality = 2;

	this->hp = 10;
	this->hpMax = 10;
	this->stamina = 10;
	this->staminaMax = 10;
	this->damageMin = 2;
	this->damageMax = 4;
	this->defence = 1;
	this->luck = 0;

} //end func

void Character::printStats() const
{
	std::cout << "+Character Stats: " << std::endl;
	std::cout << "+Name: " << this->name << std::endl;
	std::cout << "+Level: " << this->level << std::endl;
	std::cout << "+Exp: " << this->exp << std::endl;
	std::cout << "+Exp Needed: " << this->expNext << std::endl << std::endl;
	std::cout << "+Strength: " << this->strength << std::endl;
	std::cout << "+Stealth: " << this->stealth << std::endl;
	std::cout << "+Magic: " << this->magic << std::endl;
	std::cout << "+Hacking: " << this->hacking << std::endl;
	std::cout << "+Vitality: " << this->vitality << std::endl << std::endl;
	std::cout << "+Hit Points:  " << this->hp << " / " << this->hpMax << std::endl;
	std::cout << "+Stamina: " << this->stamina << " / " << this->staminaMax << std::endl;
	std::cout << "+Damage: " << this->damageMin << " - " << this->damageMax << std::endl;
	std::cout << "+Defence: " << this->defence << std::endl;
	std::cout << "+Luck: " << this->luck << std::endl;
	std::cout << std::endl << std::endl;
} //end func

void Character::levelUp()
{
	while (this->exp >= this->expNext)
	{
		this->exp = this->expNext;
		this->level++;

		this->expNext = static_cast<int>((50 / 3)*((pow(level, 3)
			- 6 * pow(level, 2))
			+ 17 * level - 12)) + 100;

		this->statPoints++;
		this->skillPoints++;
	}
} //end func