#include "Player.h"

// а здесь уже вс€ реализаци€

Player::Player() {
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
		std::cout << "поздравл€ю, вы повысили уровень" << std::endl;

	}
}
