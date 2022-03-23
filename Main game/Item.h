#pragma once
#include <iostream>

enum Rare {
	NORMAL,
	MEDIUM,
	RARE,
	LEGENDARY,
	MITHIC,
	MAXRAREITEM
};

class Item
{
protected: 
	std::string name;
	int price;
	Rare rarity;

public:
	std::string GetName() { return name; }
	Rare GetRarity() { return rarity; }
	virtual int GetPrice()	 { return price;}

};


