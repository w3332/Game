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
	if (itemname == "ничего") {
		cout << "вы обшманали монстра но ничего не нашли" << endl;
		return;
	}
	WriteText("Вы положили " + itemname + " в инвентарь\n", 40);
	if (backpack[itemname] >= 0) {	backpack[itemname] += 1; } //если есть такой предмет увеличиваем кол-во
	else {	backpack[itemname] = 1;	} //иначе создаём новый объект
	system("pause");
}

void Player::LookInBackpack()
{
	int count = 0;
	#if DEBUG
	WriteText("Ваш инвентарь:\n", 50);
	#endif
	for (auto &itemname : backpack)
	{
		count++;
		std::cout << "#" << count << ": " << itemname.first << " - " << itemname.second << std::endl;
	}
	system("pause");
}

void Player::UseItem()
{
	vector<string> myitem;
	for (auto name : backpack) {
		myitem.push_back(name.first);
	}
	cout << "Что из инвентаря вы хотите использовать?" << endl;
	int count = 0;
	for (auto item : myitem) {
		count++;
		cout << "#"<< count << " - " << item << endl;
	}
	cout << "Выберите номер предмета: ";
	int a = CheckingInput(1,myitem.size());
	cout << "Вы хотите использовать " << myitem[a-1] << "?" << endl << 
		"1 - Да\n2 - Нет\n";
	a = CheckingInput(1, 2);
	if (a == 1) {
		backpack[myitem[a-1]] -= 1;
		WhatItemDoing(myitem[a-1]);
	}
	
	
	
	
}

void Player::WhatItemDoing(string itemName)
{
	if (itemName == "Свиток") {
		int a = rand() % 5;
		defence += a;
		cout << "Ваша защита увеличилась на " << a << ". Текущая защита равна " << defence << endl;
		system("pause");
	}
	else if (itemName == "Лечебное зелье") {
		int a = rand() % 31;
		health += a;
		cout << "Вы восстановили " << a << " здоровья. Текущее здоровье равно " << health << endl;
		system("pause");
	}
	
}
