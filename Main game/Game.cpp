#include "Game.h"

void Game::FirstMessage()
{
	string message1 = "A ты не из робкого десятка!\nЕсли коротко, то тебе нужно найти выход и не сдохнуть.\n";
	WriteText(message1, 20);
	string message2 = "Справишься ? Смотри, я на тебя поставил, не разочаруй меня!\n\n";
	WriteText(message2, 10);
}

void Game::StartScreen()
{
	while (continueGame)
	{
		system("cls"); // очищает экран консоли

		cout << " 1. Начать игру\n" <<
			" 2. Загрузит игру\n" <<
			" 3. Помощь\n" <<
			" 4. Выйти\n" <<
			"\nВыбери пункт меню: ";

		short int choice = CheckingInput(1,4); 
		switch (choice) {
		case 1:
			StartAdventure();
			break;
		case 2:
			// << реализовать фаил загрузки
			break;
		case 3:
			WriteText("Тут ничего сложного! Сам разберёшься по ходу дела!\n", 30);
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

		cout << "Ты стоишь посреди глуши.\n\n" <<
				"1. Идём туда\n" <<
				"2. Идём сюда\n" <<
				"3. Идём куда то\n" <<
				"4. Идём в запой\n" <<
				"5. Стоим на месте\n\n"<< 
				"Твои дальнейшие действия: ";
			
		int choice = CheckingInput(1,5);
		Monster mon(SelectMonster());
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
		default:
			break;
		}
		count++;

		if (player.CheckLife())
		{
			string finishMessage = "Тебе п...здец!\nИгра окончена.\n";
			WriteText(finishMessage, 50);
			system ("pause");
			break;
		}
		if (player.GetLevel() >= 10) 
		{	
			WriteText("Красавчик! Ты победил!", 50);
			break;
		}
		system("pause");
	}

}

