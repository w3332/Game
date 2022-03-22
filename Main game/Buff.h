#pragma once
#include "Item.h"

enum BuffType
{
	POTION,
	SCROLL,
	MAXIM

};

class Buff : public Item   
{
private:
	int value;
public:
	Buff()
	{
		
	}
	int GetValue() {
		return value;
	}

};