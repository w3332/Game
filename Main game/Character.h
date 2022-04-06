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
	// возвращает true если уровень здоровья меньше 0
	bool IsDead();

	// рассчитывает урон, который нанесёт юнит по персонажу
	int DamageReceived(Character& unit);

	// отнимает урон из текущего здоровья 
	void ReducedHealth(int totalDamage) { health = CheckHealth(health - totalDamage); };

	// если значение меньше 0 возвращает 0
	int CheckHealth(int hp);

	virtual std::string GetName() { return name; }
	virtual int GetHealth() { return health; }
	AttackType GetType() { return attackType; }
	
};