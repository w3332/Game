#include "Game.h"

void Game::FirstMessage()
{
	string message1 = "A �� �� �� ������� �������!\n���� �������, �� ���� ����� ����� ����� � �� ��������.\n";
	WriteText(message1, 20);
	string message2 = "���������� ? ������, � �� ���� ��������, �� ��������� ����!\n\n";
	WriteText(message2, 10);
}

void Game::StartScreen()
{
	while (continueGame)
	{
		system("cls"); // ������� ����� �������

		cout << " 1. ������ ����\n" <<
			" 2. �������� ����\n" <<
			" 3. ������\n" <<
			" 4. �����\n" <<
			"\n������ ����� ����: ";

		string messageHelp = "��� ������ ��������! ��� ���������� �� ���� ����!\n";
		short int choice;
		cin >> choice;

		switch (choice) {
		case 1:
			StartAdventure();
			break;
		case 2:
			// << ����������� ���� ��������
			break;
		case 3:
			WriteText(messageHelp, 30);
			system("pause");
			break;
		case 4:
			continueGame = false;
			break;
		default:
			cout << "�������� �����! �������� �����\n"; Sleep(2000);
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
		if (count == 0) FirstMessage();
		
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

		//Monster monst(SelectMonster());
		//Battle(player, monst);

		if (player.CheckLife())
		{
			string finishMessage = "���� �...����!\n���� ��������.\n";
			WriteText(finishMessage, 50);
			system ("pause");
			break;
		}
	}
}

