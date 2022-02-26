#include "Player.h"

Player::Player() {
	name = "Noname";
	level = 1;
	health = 100;
	damage = 10;
	defence = 1;
}

void Player::LevelUp()
{
	if (exp >= expMax)
	{
		level++;
		exp = exp - expMax;
		expMax = level * 100;
		health = health + 50;
		damage = damage + 5;
		std::cout << "Поздравляю! Вы повысили уровень." << std::endl;
	}
}
