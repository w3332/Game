#include"Monster.h"

Monster::Monster(MonsterType type) {
	switch (type)
	{
	case SKELETON:
		health = 50;
		damage = 5;
		defence = 0;
		break;
	case ORC:
		health = 100;
		damage = 15;
		defence = 10;
		break;
	case LICH:
		health = 150;
		damage = 25;
		defence = 20;
		break;
	case DRACON:
		health = 200;
		damage = 50;
		defence = 50;
		break;
	default:
		break;
	}
}