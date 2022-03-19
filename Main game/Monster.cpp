#include"Monster.h"

Monster::Monster(MonsterType type) 
{
	switch (type)
	{
	case SKELETON:
		name = "Skeleton";
		health = 50;
		damageMin = 5;
		damageMax = 10;
		defence = 0;
		thisMonster = type;

		break;
	case ORC:
		name = "Orc";
		health = 100;
		damageMin = 15;
		damageMax = 25;
		defence = 10;
		thisMonster = type;
		break;
	case LICH:
		name = "Lich";
		health = 150;
		damageMin = 25;
		damageMax = 35;
		defence = 15;
		thisMonster = type;
		break;
	case DRAGON:
		name = "Dragon";
		health = 200;
		damageMin = 45;
		damageMax = 55;
		defence = 30;
		thisMonster = type;
		break;
	case BOSS:
		name = "Boss";
		health = 400;
		damageMin =90;
		damageMax = 110;
		defence = 45;
		thisMonster = type;
	default:
		break;
	}
}