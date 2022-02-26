#include"Monster.h"

Monster::Monster(MonsterType type) 
{
	switch (type)
	{
	case SKELETON:
		name = "Skeleton";
		health = 50;
		damage = 5;
		defence = 0;
		break;
	case ORC:
		name = "Orc";
		health = 100;
		damage = 15;
		defence = 10;
		break;
	case LICH:
		name = "Lich";
		health = 150;
		damage = 25;
		defence = 20;
		break;
	case DRAGON:
		name = "Dragon";
		health = 200;
		damage = 50;
		defence = 50;
		break;
	default:
		break;
	}
}