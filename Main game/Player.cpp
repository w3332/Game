#include "Player.h"

Player::Player()
{  
	// ����� �� ���������
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
	
	while (exp >= expMax) // ���� ������� ���-�� ���� ���� ������������ ���������, �������� �������
	{
		// ���������� ������������� ��� ���-���
		std::cout << "�����������! �� �������� �������.\n";
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
	if (itemname == "������") {
		cout << "�� ��������� ������� �� ������ �� �����" << endl;
		return;
	}
	WriteText("�� �������� " + itemname + " � ���������\n", 40);
	if (backpack[itemname] >= 0) {	backpack[itemname] += 1; } //���� ���� ����� ������� ����������� ���-��
	else {	backpack[itemname] = 1;	} //����� ������ ����� ������
	system("pause");
}

void Player::LookInBackpack()
{
	int count = 0;
	#if DEBUG
	WriteText("��� ���������:\n", 50);
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
	cout << "��� �� ��������� �� ������ ������������?" << endl;
	int count = 0;
	for (auto item : myitem) {
		count++;
		cout << "#"<< count << " - " << item << endl;
	}
	cout << "�������� ����� ��������: ";
	int a = CheckingInput(1,myitem.size());
	cout << "�� ������ ������������ " << myitem[a-1] << "?" << endl << 
		"1 - ��\n2 - ���\n";
	a = CheckingInput(1, 2);
	if (a == 1) {
		backpack[myitem[a-1]] -= 1;
		WhatItemDoing(myitem[a-1]);
	}
	
	
	
	
}

void Player::WhatItemDoing(string itemName)
{
	if (itemName == "������") {
		int a = rand() % 5;
		defence += a;
		cout << "���� ������ ����������� �� " << a << ". ������� ������ ����� " << defence << endl;
		system("pause");
	}
	else if (itemName == "�������� �����") {
		int a = rand() % 31;
		health += a;
		cout << "�� ������������ " << a << " ��������. ������� �������� ����� " << health << endl;
		system("pause");
	}
	
}
