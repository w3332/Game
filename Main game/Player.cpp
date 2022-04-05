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
	expMax = 100;
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
		expMax += level * 100;
		health += 70;
		damageMin += 5;
		damageMax += 7;
		defence += 5;
	}

}

void Player::PutInBag(std::string itemname)
{
	if (itemname == "ничего") {
		WriteText("Вы осмотрели монстра но ничего ценного не нашли\n", 30);
		system("pause");
		return;
	}
	WriteText("Вы положили " + itemname + " в инвентарь\n", 20);
	if (backpack[itemname] >= 0) backpack[itemname] += 1; //если есть такой предмет увеличиваем кол-во
	else backpack[itemname] = 1;						  //иначе создаём новый объект
	system("pause");
}

void Player::LookInBag()
{
	int count = 0;
	#if DEBUG
	WriteText("Ваш инвентарь:\n", 40);
	#endif
	for (auto& itemname : backpack)
	{
		count++;
		std::cout << "#" << count << ": " << itemname.first << " - " << itemname.second << std::endl;
	}
	system("pause");
}

void Player::UseItem()
{
	cout << "Что из инвентаря вы хотите использовать?\nВыберите номер предмета: ";
	int i = 1, a = CheckingInput(1, backpack.size());
	string myitem;
	for (auto val : backpack)
	{
		if (i == a)
			myitem = val.first;
		i++;
	}
	cout << "Вы хотите использовать " << myitem << "?\n1 - Да\n2 - Нет\n";
	a = CheckingInput(1, 2);
	if (a == 1) {
		backpack[myitem] -= 1; // уменьшаем кол-во предмета в инвентаре
		CheckItem();		   // если количество равно 0, то удаляем его
		WhatItemDoes(myitem);
	}
}

void Player::WhatItemDoes(string itemName)
{
	if (itemName == "Свиток") {
		int a = rand() % 5;
		defence += a;
		cout << "Ваша защита увеличилась на " << a << ". Текущая защита равна " << defence << endl;
	}
	else if (itemName == "Лечебное зелье") {
		int a = rand() % 10 + 20;
		health += a;
		cout << "Вы восстановили " << a << " здоровья. Текущее здоровье равно " << health << endl;
	}
		system("pause");

}

void Player::PrintCharacter()
{
	cout << "\nВаш уровень: " << level <<
		"\nУрон: " << damageMin << " - " << damageMax <<
		"\nЗащита: " << defence <<
		"\nЗдоровье: " << health <<
		"\nТекущий опыт: "<< exp<<
		"\nДо следующего уровня осталось: "<<
		expMax-exp<< endl;

	system("pause");
}

void Player::CheckItem()
{
	string name;
	for (auto val : backpack) {
		if (val.second <= 0) {
			name = val.first;
		}
	}
	backpack.erase(name);
}

bool Player::AnythingInBag()
{
	if (backpack.size() > 0) return true;
	else return false;
}
