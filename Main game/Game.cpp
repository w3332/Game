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

		short int choice = CheckingInput(1,4); 
		switch (choice) {
		case 1:
			StartAdventure();
			break;
		case 2:
			// << ����������� ���� ��������
			break;
		case 3:
			WriteText("��� ������ ��������! ��� ���������� �� ���� ����!\n", 30);
			system("pause");
			break;
		case 4:
			continueGame = false;
			break;
		
		default:
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
		#if DEBUG
		if (count == 0) FirstMessage();
		#endif

		cout << "�� ������ ������� �����.\n\n" <<
				"1. ��� ����\n" <<
				"2. ��� ����\n" <<
				"3. ��� ���� ��\n" <<
				"4. ��� � �����\n" <<
			    "5. ���������\n"<<
				"6. ������� ��... ����� �� ����!\n\n"<< 
				"���� ���������� ��������: ";
			
		int choice = CheckingInput(1,5);
		Monster mon(SelectMonster(player.GetLevel()));
		switch (choice)
		{
		case 1:
			CollisionMonster(mon,player);
			break;
		case 2:
			CollisionMonster(mon, player);
			break;
		case 3:
			CollisionMonster(mon, player);
			break;
		case 4:
			CollisionMonster(mon, player);
			break;
		case 5:
			//player.LookInventory();
			return;
		case 6:
			return;
		default:
			break;
		}
		count++;

		if (player.CheckLife()) {
			WriteText("���� �...����!\n���� ��������.\n", 100);
			system ("pause");
			break;
		}
		if (player.GetLevel() >= 10) {	
			WriteText("���������! �� �������!\n", 100);
			system("pause");
			break;
		}
		system("pause");
	}

}

