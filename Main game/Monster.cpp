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
		thisMonster = type;

		break;
	case ORC:
		name = "Orc";
		health = 100;
		damage = 15;
		defence = 10;
		thisMonster = type;
		break;
	case LICH:
		name = "Lich";
		health = 150;
		damage = 20;
		defence = 15;
		thisMonster = type;
		break;
	case DRAGON:
		name = "Dragon";
		health = 200;
		damage = 30;
		defence = 30;
		thisMonster = type;
		break;
	default:
		break;
	}
}