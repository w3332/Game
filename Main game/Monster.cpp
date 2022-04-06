#include"Monster.h"

Monster::Monster(MonsterType type) 
{
	switch (type)
	{
	case SKELETON:
		name = "Skeleton";
		health = 80;
		damagePh = 15;
		defencePh = 2;
		thisMonster = type;
		attackType = AttackType::PHYSICAL;

		break;
	case ORC:
		name = "Orc";
		health = 150;
		damagePh = 30;
		defencePh = 10;
		thisMonster = type;
		attackType = AttackType::PHYSICAL;
		break;
	case LICH:
		name = "Lich";
		health = 250;
		damageMg = 50;
		defenceMg = 15;
		thisMonster = type;
		attackType = AttackType::MAGIC;
		break;
	case DRAGON:
		name = "Dragon";
		health = 500;
		damageMg = 100;
		defenceMg =35;
		thisMonster = type;
		attackType = AttackType::MAGIC;
		break;
	case BOSS:
		name = "Boss";
		health = 1000;
		damageMg = 200;
		defenceMg = 50;
		thisMonster = type;
		attackType = AttackType::MAGIC;
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
