#include "Character.h"

// ���������� true ���� ������� �������� ������ 0
bool Character::CheckLife()
{
	if (health <= 0)
		return true;
	else
		return false;
}

// ������������ ����, ������� ������ unit
int Character::DamageToCharacter(Character& unit)
{
	int damage = rand() % (unit.damageMax - unit.damageMin) + unit.damageMin;
	int totalDamage = damage - this->defence;
	if (totalDamage < 0)
		totalDamage = 0;
	return totalDamage;
}

// �������� ���������� ���� �� �������� ��������
void Character::DealDamage(int totalDamage)
{
	this->health -= totalDamage;
}

std::string Character::GetName()
{
	return this->name;
}


