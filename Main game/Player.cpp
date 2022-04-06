#include "Player.h"

Player::Player()
{
	// ����� �� ���������
	name = "Noname";
	level = 1;
	health = 200;
	damageMg = 30;
	damagePh = 20;
	defencePh= 5;
	defenceMg = 5;
	exp = 0;
	expMax = 100;
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
		expMax += level * 100;
		health += 70;
		damageMg += 5;
		damagePh += 7;
		defenceMg += 5;
		defencePh += 5;
		
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
		defenceMg += a;
		cout << "���� ���������� ������ ����������� �� " << a << ". ������� ������ ����� " << defenceMg << endl;
	}
	else if (itemName == "�������� �����") {
		int a = rand() % 10 + 20;
		health += a;
		cout << "�� ������������ " << a << " ��������. ������� �������� ����� " << health << endl;
	}
		system("pause");

}

void Player::PrintCharacter()
{
	cout << "\n��� �������: " << level <<
		"\n���� (����������/����������): " << damagePh<<" / " << damageMg <<
		"\n������(����������/����������): " << defencePh << " / " << defenceMg <<
		"\n��������: " << health <<
		"\n������� ����: "<< exp<<
		"\n�� ���������� ������ ��������: "<< expMax-exp<< endl;

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