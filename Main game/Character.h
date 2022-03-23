#pragma once
#include<iostream>

class Character
{
protected:
	int health;
	int damageMin, damageMax;
	int defence;
	std::string name;

public:
	// ���������� true ���� ������� �������� ������ 0
	bool IsDead();

	// ������������ ����, ������� ������ ���� �� ���������
	int DamageReceived(Character&unit);

	// �������� ���� �� �������� �������� 
	void ReducedHealth(int totalDamage) { health = CheckHealth(health - totalDamage); };

	// ���� �������� ������ 0 ���������� 0
	int CheckHealth(int hp);	

	virtual std::string GetName() { return name; }
	virtual int GetHealth() { return health; }

};



