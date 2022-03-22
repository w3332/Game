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

MonsterType SelectMonster(int level) {
	if (level <= 3) {
		level = 3;
	}
	else if (level > 3 && level <= 6) {
		level = 2;
	}
	else if (level >6  && level <=9) {

		level = 1;
	}
	else {
		level = 0;
	}
	MonsterType type = MonsterType(rand() % (MonsterType::MAXMON-level));

	return type;
}

void CollisionMonster(Monster &mon,Player &plr)
{

	cout << "\n����� ���� �������� " << mon.GetName() <<
			"\n���� ���������� ��������:\n" <<
			"1.���������\n" <<
			"2.�������\n\n";
	int g = CheckingInput(1, 2);
	if (g == 1) {

		Battle(mon,plr);
	}
	else if (g == 2) {
		int q = rand() % 2;
		if (q == 0) {
			cout << " ��� ������� ������� " << endl;
	
		}
		else if (q == 1) {
			int damageMon = plr.DamageToCharacter(mon)*1.5;
			cout << " ��� �� ������� �������. " << mon.GetName() << " ���� ��� " << damageMon << " ����� " << endl;
			plr.DealDamage(damageMon);
			system("pause");
			Battle(mon, plr);
		}
		
	}
	

}

void Battle(Monster &mon, Player &plr)
{
	while(true) {
		system("cls"); // ������� ����� �������
		int damageMon = plr.DamageToCharacter(mon);
		int damagePlr = mon.DamageToCharacter(plr);

		WriteText("�� ���� � ����� � �������� ", 20);
		cout<< damagePlr << " �����" << endl;
		mon.DealDamage(damagePlr);
		WriteText("������� �������� ������� ", 20);
        cout  << CheckHealth(mon.GetHealth()) << "\n\n";

		if (mon.CheckLife()) {
			plr.LevelUp(mon.GetType());//�������� ���� 
			//plr.AddToInventory();

			break;
		}
		else  {
			cout << mon.GetName() << " ���� ��� " << damageMon << " �����" << endl;
			plr.DealDamage(damageMon);
			WriteText("���� ������� �������� = ", 20);
			cout  << CheckHealth( plr.GetHealth()) << endl;

		}

		if (plr.CheckLife()) {
			break;
		}


		system("pause");
	}
}

int CheckHealth(int hp)
{
	if (hp < 0) {
		hp = 0;
		
	}
	return hp;
}
