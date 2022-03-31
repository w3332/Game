#pragma once
#include <map>
#include <vector>

#include "Character.h"
#include "Function.h"

class Player : public Character
{
private:
	int level, exp ,expMax;
	map<string, int> backpack;
public:
	Player();
	
	// увеличивает опыта
	void Experience(int expr);

	// положить что то в инвентарь
	void PutInBag(string itemname);

	// посмотреть инвентарь
	void LookInBag();

	// удаляет предмет из инвентаря, который закончился
	void CheckItem();

	// возвращает true если в инвентаре что то есть
	bool AnythingInBag();

	// предлагаем игроку использовать предмет из инвентаря
	void UseItem();

	// реализует предмет из инвентаря
	void WhatItemDoes(string itemName);

	void SetName (string name) { this->name = name; }
	int GetLevel() { return level;}
};



