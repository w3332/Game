#include "Character.h"

bool Character::CheckLife()
{
	if (health <= 0)
	{
		return true;

	}
	return false;
}

void Character::GetDamage(Character& unit)
{
	health -= unit.damage - defence;
}
