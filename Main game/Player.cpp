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
	
	while (exp >= expMax) // ���� ������� ���� ���� ������������ ���������, �������� �������
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
