#pragma once
#include "Function.h"

enum Rare {
	NORMAL,
	MEDIUM,
	RARE,
	LEGENDARY,
	MITHIC
};

class Item
{
protected: 
	std::string name;
	int price;
	Rare rarity;

public:
	Item(){}
	Item(Rare type) { rarity = type; }

	string GetName() { return name; }
	int GetPrice()	 { return price;}

};


