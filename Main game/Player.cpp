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
	
	while (exp >= expMax) // пока текущее кол-во опыт выше необходимого максимума, повышаем уровень
	{
		// увеличение характеристик при лвл-апе
		std::cout << "Поздравляем! Вы повысили уровень.\n";
		level++;
		exp -= expMax;
		expMax += level * 10;
		health += 70;
		damageMin += 5;
		damageMax += 7;
		defence += 5;
	}

}

void Player::PutInBackpack(std::string itemname)
{
	WriteText("Вы положили " + itemname + " в инвентарь\n", 40);
	if (backpack[itemname] >= 0) {	backpack[itemname] += 1; } //если есть такой предмет увеличиваем кол-во
	else {	backpack[itemname] = 1;	} //иначе создаём новый объект
	system("pause");
}

void Player::LookInBackpack()
{
	int count = 0;
	WriteText("Ваш инвентарь:\n", 50);
	for (auto &itemname : backpack)
	{
		count++;
		std::cout << "#" << count << ": " << itemname.first << " - " << itemname.second << std::endl;
	}
	system("pause");
}
