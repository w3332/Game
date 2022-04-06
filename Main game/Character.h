#pragma once
#include<iostream>

enum AttackType {
	PHYSICAL,
	MAGIC,
	MAX_AT

};

class Character
{
protected:
	int health;
	int damageMg = 1, damagePh = 1;
	int defencePh = 1, defenceMg = 1;
	std::string name;
	AttackType attackType = AttackType::PHYSICAL;


public:
	// ���������� true ���� ������� �������� ������ 0
	bool IsDead();

	// ������������ ����, ������� ������ ���� �� ���������
	int DamageReceived(Character& unit);

	// �������� ���� �� �������� �������� 
	void ReducedHealth(int totalDamage) { health = CheckHealth(health - totalDamage); };

	// ���� �������� ������ 0 ���������� 0
	int CheckHealth(int hp);

	virtual std::string GetName() { return name; }
	virtual int GetHealth() { return health; }
	AttackType GetType() { return attackType; }
	
};