#include "Game.h"
#include"Function.h"
#include"Character.h"

void Game::StartScreen()
{
	while (continueGame)
	{
		system("cls"); // ������� ����� �������

		cout << " 1. ������ ����\n" <<
			" 2. �������� ����\n" <<
			" 3. ������\n" <<
			" 4. �����\n" <<
			"\n�������� ����� ����: ";
		short int choice;
		cin >> choice;

		switch (choice) {
		case 1:
			StartAdventure();
			break;
		case 2:
			break;
		case 3:
			cout << "�� �� ��� �����������?! ��� ���������� ��� ������!";
			Sleep(3000);
			break;
		case 4:
			continueGame = false;
			break;
		default:
			cout << "�������� �����! ���������� �����\n"; Sleep(2000);
			cin.clear(); cin.ignore(32767, '\n');  // ������� �����
			choice = NULL;
			break;
		}
	}
}

void Game::StartAdventure()
{
	int count = 0;
	Player player;
	while (true)
	{
		system("cls");
		if (count == 0)
		{
			string str = "A �� �� �� ������� �������!\n���� �������, �� ���� ����� ����� ����� � �� ��������.\n����������? ������, � �� ���� ��������, �� ��������� ����!\n\n";
			WriteText(str, 50);
		}
		cout << "�� ������ ������� �����. ���� ���������� ��������?\n\n" <<
				"1. ��� �� �����\n" <<
				"2. ��� �� ������\n" <<
				"3. ��� �� ��\n" <<
				"4. ��� �� �����\n" <<
				"5. ������ �� ���. ���� ��� ���������?\n";
			
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			break;
		default:
			break;
		}
		count++;
		Monster monst(SelectMonster());
		Battle(player, monst);
		if (player.CheckLife())
		{
			cout << "���� ��..�" << endl;
			Sleep(2000);
			break;
		}
	}
}

