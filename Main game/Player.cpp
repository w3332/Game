#include "Player.h"

Player::Player() {
	name = "Noname";
	level = 1;
	health = 200;
	damageMin = 15;
	damageMax = 35;
	defence = 1;
	exp = 0;
	expMax = 50;
}

void Player::LevelUp(MonsterType type)
{
	
	switch (type)
	{
	case SKELETON:
		exp += 50;
		break;
	case ORC:
		exp += 100;
		break;
	case LICH:
		exp += 160;
		break;
	case DRAGON:
		exp += 200;
		break;
	case MAX:
		break;
	default:
		break;
	}

	if (exp >= expMax)
	{
		level++;
		exp = exp - expMax;
		expMax += level * 50;
		health = health + 50;
		damageMin +=  5;
		damageMax += 7;
		defence += 5;
		std::cout << "ѕоздравл€ю! ¬ы повысили уровень." << std::endl;
	}
	std::cout << "ваш текущий уровень " << level << std::endl << "до следующего уровн€ осталось " << expMax - exp << " опыта"<<std::endl;
		
}
