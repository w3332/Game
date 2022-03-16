#include "Function.h"

void WriteText(const string& text, int printSpeed)
{
	Sleep(printSpeed * 10);
	for (char var : text)
	{
		if (var == ' ')
			Sleep(printSpeed + 20);
		cout << var;
		Sleep(printSpeed);
	}
	Sleep(printSpeed * 10);
}

int CheckingInput(int minValue, int maxValue)
{
	int value;
	while (true)
	{
		cin >> value;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
		{
			std::cin.ignore(32767, '\n');
			if (value >= minValue && value <= maxValue)
				return value;
		}
		std::cout << "�������� �����! �������� �����: ";
	}
}

MonsterType SelectMonster() {

	MonsterType type = MonsterType(rand() % MonsterType::MAX);
	return type;
}

void CollisionMonster(Monster &mon,Player &plr)
{

	cout << "����� ���� �������� " << mon.GetName() << endl;
	cout << "���� ���������� ��������:" << endl;
	cout << "1.���������" << endl << "2.�������" << endl;
	int g = CheckingInput(1, 2);
	if (g == 1) {

		Battle(mon,plr);
	}
	

}

void Battle(Monster &mon, Player &plr)
{
	while(true) {
		int damageMon = plr.DamageToCharacter(mon);
		int damagePlr = mon.DamageToCharacter(plr);
		cout << "�� ���� � ����� � �������� " << damagePlr << " �����" << endl;
		mon.DealDamage(damagePlr);
		WriteText("������� �������� ������� ", 20);
		cout  << mon.GetHealth() << endl;

		if (mon.CheckLife()) {
			plr.LevelUp(mon.GetType());//�������� ���� 
			break;

		}
		else  {
			cout << mon.GetName() << " ���� ��� " << damageMon << " �����" << endl;
			plr.DealDamage(damageMon);
			WriteText("���� ������� �������� = ", 20);
			
			cout  << plr.GetHealth() << endl;

		}

		if (plr.CheckLife()) {
			break;
		}


		system("pause");
	}
}
