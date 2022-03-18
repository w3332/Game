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
	int totalDamage = damage - this->defence;
	if (totalDamage < 0)
		totalDamage = 0;
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


