#include "Character.h"

bool Character::IsDead()
{
	if (health <= 0)
		return true;
	else
		return false;
}

int Character::DamageReceived(Character& unit)
{
	// урон юнита в диапазоне от его мин. до макс. урона
	int damage = rand() % (unit.damageMax - unit.damageMin) + unit.damageMin;
	// защита в диапазоне от 50% до 100% текущего значения
	int defence = rand() % (this->defence - this->defence / 2) + this->defence / 2;
	int totalDamage = damage - defence;
	if (totalDamage < 1)
		totalDamage = 1; // минимальный урон не должен быть меньше 1
	return totalDamage;
}

int Character::CheckHealth(int hp)
{
	if (hp < 0) { hp = 0; }
	return hp;
}



