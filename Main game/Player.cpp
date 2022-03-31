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

void Player::PutInBag(std::string itemname)
{
	if (itemname == "������") {
		WriteText("�� ��������� ������� �� ������ ������� �� �����\n", 30);
		system("pause");
		return;
	}
	WriteText("�� �������� " + itemname + " � ���������\n", 20);
	if (backpack[itemname] >= 0) backpack[itemname] += 1; //���� ���� ����� ������� ����������� ���-��
	else backpack[itemname] = 1;						  //����� ������ ����� ������
	system("pause");
}

void Player::LookInBag()
{
	int count = 0;
	#if DEBUG
	WriteText("��� ���������:\n", 40);
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
	cout << "��� �� ��������� �� ������ ������������?\n�������� ����� ��������: ";
	int i = 1, a = CheckingInput(1, backpack.size());
	string myitem;
	for (auto val : backpack)
	{
		if (i == a)
			myitem = val.first;
		i++;
	}
	cout << "�� ������ ������������ " << myitem << "?\n1 - ��\n2 - ���\n";
	a = CheckingInput(1, 2);
	if (a == 1) {
		backpack[myitem] -= 1; // ��������� ���-�� �������� � ���������
		CheckItem();		   // ���� ���������� ����� 0, �� ������� ���
		WhatItemDoes(myitem);
	}
}

void Player::WhatItemDoes(string itemName)
{
	if (itemName == "������") {
		int a = rand() % 5;
		defence += a;
		cout << "���� ������ ����������� �� " << a << ". ������� ������ ����� " << defence << endl;
	}
	else if (itemName == "�������� �����") {
		int a = rand() % 10 + 20;
		health += a;
		cout << "�� ������������ " << a << " ��������. ������� �������� ����� " << health << endl;
	}
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