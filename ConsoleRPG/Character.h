#ifndef CHARACTER_H
#define	CHARACTER_H

#include "Inventory.h"

class Character
{
public:
	Character();
	virtual ~Character();

	//functions
	void initliaze(const std::string name);
	void printStats() const;
	void levelUp();

	//accessors
	inline const std::string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getHp() const { return this->hp; }
	inline const int& getHpMax() const { return this->hpMax; }
	inline const int& getStamina() const { return this->stamina; }
	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int& getDefence() const { return this->defence; }

	inline const double& getXPos() const { return this->xPos; }
	inline const double& getYPos() const { return this->yPos; }

	//modifiers

private:
	double xPos;
	double yPos;

	std::string name;
	int level;
	int exp;
	int expNext;

	int statPoints;
	int skillPoints;

	int strength;
	int stealth;
	int magic;
	int hacking;
	int vitality;

	int hp;
	int hpMax;
	int stamina;
	int staminaMax;
	int damageMin;
	int damageMax;
	int defence;
	int luck;
};

#endif