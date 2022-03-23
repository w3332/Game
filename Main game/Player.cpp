#include "Player.h"

Player::Player()
{  
	// статы по умолчанию
	name = "Noname";
	level = 1;
	health = 200;
	damageMin = 15;
	damageMax = 35;
	defence = 5;
	exp = 0;
	expMax = 50;
}

void Player::Experience(int expr)
{
	exp += expr;
	
	while (exp >= expMax) // пока текущий опыт выше необходимого максимума, повышаем уровень
	{
		// увеличение характеристик при лвл-апе
		std::cout << "ѕоздравл€ем! ¬ы повысили уровень.\n";
		level++;
		exp -= expMax;
		expMax += level * 10;
		health += 70;
		damageMin += 5;
		damageMax += 7;
		defence += 5;
	}

}
