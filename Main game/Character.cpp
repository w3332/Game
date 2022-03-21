#include "Character.h"

// возвращает true если уровень здоровья меньше 0
bool Character::CheckLife()
{
	if (health <= 0)
		return true;
	else
		return false;
}

// рассчитывает урон, который нанесёт unit
int Character::DamageToCharacter(Character& unit)
{
	int damage = rand() % (unit.damageMax - unit.damageMin) + unit.damageMin;
	int defence = rand() % (this->defence - this->defence / 2) + this->defence / 2;
	int totalDamage = damage - defence;
	if (totalDamage < 1)
		totalDamage = 1;
	return totalDamage;
}

// вычитает полученный урон из текущего здоровья
void Character::DealDamage(int totalDamage)
{
	this->health -= totalDamage;
}

std::string Character::GetName()
{
	return this->name;
}


