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
	int damageMin, damageMax;
	float ratio = 0.25f;
	if (attackType == AttackType::PHYSICAL) {

		damageMin = unit.damagePh - unit.damagePh * ratio;
		damageMax = unit.damagePh + unit.damagePh * ratio;
		// урон юнита в диапазоне от его мин. до макс. урона
		int damage = rand() % (damageMax - damageMin) + damageMin;
		// защита в диапазоне от 50% до 100% текущего значения
		int defence = rand() % (this->defencePh - this->defencePh / 2) + this->defencePh / 2;
		int totalDamage = damage - defence;
		if (totalDamage < 1)
			totalDamage = 1; // минимальный урон не должен быть меньше 1
		return totalDamage;
	}
	else if (attackType == AttackType::MAGIC) {
		damageMin = unit.damageMg - unit.damageMg * ratio;
		damageMax = unit.damageMg + unit.damageMg * ratio;
		// урон юнита в диапазоне от его мин. до макс. урона
		int damage = rand() % (damageMax - damageMin) + damageMin;
		// защита в диапазоне от 50% до 100% текущего значения
		int defence = rand() % (this->defenceMg - this->defenceMg / 2) + this->defenceMg / 2;
		int totalDamage = damage - defence;
		if (totalDamage < 1)
			totalDamage = 1; // минимальный урон не должен быть меньше 1
		return totalDamage;
	}
}

int Character::CheckHealth(int hp)
{
	if (hp < 0) { hp = 0; }
	return hp;
}



