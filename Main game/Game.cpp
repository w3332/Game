#include "Game.h"

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

		choice = CheckingInput(1,4); 
		switch (choice) 
		{
		case 1:
			StartAdventure();
			break;
		case 2:
			// ����������� ���� ��������
			break;
		case 3:
			WriteText("��� ������ ��������! ��� ���������� �� ���� ����!\n", 30);
			// ������� ������ FAQ ��� ���� ������
			system("pause");
			break;
		case 4:
			continueGame = false; // ��������� ����
			break;
		default:
			break;
		}
		Player newplayer;
		player = newplayer; // ���������� ������
	}
}

bool Game::EndGame()
{
	if (player.IsDead())
	{
		WriteText("�� �������! ����������� ��������.", 40);
		Sleep(2000);
		return true;
	}
	else if (player.GetLevel() >= 10)
	{
		WriteText("�����������! �� �������� 10 ������,� ������ �� ����� ������ ������ �� ������!\n.", 40);
		Sleep(4000);
		return true;
	}
	else
	{
		return false;
	}
}

void Game::StartAdventure()
{
	while (!(Game::EndGame())) // ���� �� ��������� ���� �� ������� ��������� ����
	{
		system("cls"); // ������� ����� �������
		
		cout << "�� ������ ������� �����. ����� ��� �� ������...\n\n" <<
				"��������:\n" <<
				" 1. �� �����\n" <<
				" 2. �� ������\n" <<
				" 3. �� ��\n" <<
				" 4. �� �����\n" <<
				"����������:\n" <<
			    " 5. ���������\n"<<
				"������:\n"
				" 6. ��������� ����\n\n" <<
				"���� ���������� ��������: ";

		choice = CheckingInput(1,6);
		switch (choice)
		{
		case 1:
			// Y++
			CollisionMonster(); // <--- ��� ������������
			break;
		case 2:
			// X++
			break;
		case 3:
			// Y--
			break;
		case 4:
			// X--
			break;
		case 5:
			player.LookInBackpack(); // ������� � ���������
			break;
		case 6:
			return; // �����
		default:
			break;
		}
		
	}

}

void Game::CollisionMonster()
{
	Monster mon(Monster::SelectMonster());
	cout << "\n����� ���� �������� " << mon.GetName() <<
		"\n� ��� ���� �����:\n" <<
		" 1. ���������\n" <<
		" 2. ����������� �������\n\n" <<
		"���� ���������� ��������: ";
		choice = CheckingInput(1, 2);
		if (choice == 1)
		{ 
			Battle(mon);
		}
		else if (choice == 2)
		{
			choice = rand() % 2;
			if (choice == 0)
			{
				cout << " ��� ������� �������!\n";
				system("pause");
			}
			else
			{
				int damageMon = player.DamageReceived(mon) * 1.5; // ������������ ���� �� ������ ��� ��������� �������
				cout << "��� �� ������� �������! " << mon.GetName() << " ���� ��� " << damageMon << " �����.\n";
				player.ReducedHealth(damageMon);
				cout << "�������� ��� �� ��������� ��������. ������� �������...\n";
				system("pause"); // ������ �� ����� ����� ������� ���
				Battle(mon);
			}
		}
	
}

void Game::Battle(Monster& mon)
{
	while (!(player.IsDead())) // ���� ����� �� ���� ��� �� �������� ������
	{
		system("cls"); // ������� ����� �������
		int damageMon = player.DamageReceived(mon);
		int damagePlr = mon.DamageReceived(player);

		WriteText("�� ���� � ����� � �������� ", 0);
		cout << damagePlr << " �����" << endl;
		mon.ReducedHealth(damagePlr);
		WriteText("������� �������� ������� ", 0);
		cout << mon.GetHealth() << "\n\n";

		if (mon.IsDead()) {
			WriteText("��� �������.\n\n", 40);
			player.Experience(mon.GetExperience());//�������� ���� 
			Buff randitem(Buff::SelectBuff()); // ������ ��������� ��������� � ������� ��� ������
			player.PutInBackpack(randitem.GetName());
			break;
		}
		else {
			cout << mon.GetName() << " ���� ��� " << damageMon << " �����" << endl;
			player.ReducedHealth(damageMon);
			WriteText("���� ������� �������� = ", 0);
			cout << player.GetHealth() << endl;
		}
		system("pause");
	}
}

