#include"Monster.h"

Monster::Monster(MonsterType type) 
{
	switch (type)
	{
	case SKELETON:
		name = "Skeleton";
		health = 80;
		damageMin = 5;
		damageMax = 15;
		defence = 2;
		thisMonster = type;

		break;
	case ORC:
		name = "Orc";
		health = 150;
		damageMin = 15;
		damageMax = 30;
		defence = 10;
		thisMonster = type;
		break;
	case LICH:
		name = "Lich";
		health = 250;
		damageMin = 25;
		damageMax = 40;
		defence = 15;
		thisMonster = type;
		break;
	case DRAGON:
		name = "Dragon";
		health = 500;
		damageMin = 45;
		damageMax = 60;
		defence = 30;
		thisMonster = type;
		break;
	case BOSS:
		name = "Boss";
		health = 1000;
		damageMin =90;
		damageMax = 110;
		defence = 50;
		thisMonster = type;
	default:
		break;
	}
}

int Monster::GetExperience()
{
	switch (thisMonster)
	{
	case SKELETON:
		return 50;
	case ORC:
		return 100;
	case LICH:
		return 200;
	case DRAGON:
		return 350;
	case BOSS:
		return 1000;
	default:
		break;
	}
}

MonsterType Monster::SelectMonster(int level)
{
	int x;
	if (level <= 3) { x = 3; }
	else if (level > 3 && level <= 6) {	x = 2;}
	else {	x = 0;}
	
	return MonsterType(rand() % (MonsterType::MAXMON - x));
}
