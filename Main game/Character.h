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
	// возвращает true если уровень здоровья меньше 0
	bool IsDead();

	// рассчитывает урон, который нанесёт юнит по персонажу
	int DamageReceived(Character&unit);

	// отнимает урон из текущего здоровья 
	void ReducedHealth(int totalDamage) { health = CheckHealth(health - totalDamage); };

	// если значение меньше 0 возвращает 0
	int CheckHealth(int hp);	

	virtual std::string GetName() { return name; }
	virtual int GetHealth() { return health; }

};



