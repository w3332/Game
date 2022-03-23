#pragma once
#include "Item.h"

enum BuffType
{
	POTION,
	SCROLL,
	MAXBUFF
};

class Buff : public Item   
{
private:
	int value;
public:
	Buff(BuffType type);
	int GetValue() { return value; }

	// возвращает рандомный тип расходника
	static BuffType SelectBuff() { return BuffType(rand() % BuffType::MAXBUFF); }

};