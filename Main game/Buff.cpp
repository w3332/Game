#include "Buff.h"

Buff::Buff(BuffType type)
{
	switch (type)
	{
	case POTION:
		name = "�������� �����";
		value = 50;
		price = 1;
		rarity = Rare::NORMAL;
		break;
	case SCROLL:
		name = "������";
		value = 10;
		price = 1;
		rarity = Rare::MEDIUM;
		break;
	
	default:
		break;
	}
}
