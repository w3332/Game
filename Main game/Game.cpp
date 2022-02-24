#include "Game.h"

void Game::StartScreen()
{
	while (continueGame)
	{
		system("cls"); // очищает экран консоли

		cout << " 1. Начать игру\n" <<
			" 2. Загрузит игру\n" <<
			" 3. Помощь\n" <<
			" 4. Выйти\n" <<
			"\nВыберите пункт меню: ";
		short int choice;
		cin >> choice;

		switch (choice) {
		case 1:
			StartAdventure();
			break;
		case 2:
			break;
		case 3:
			cout << "Да чё тут непонятного?! Сам разберёшься как играть!";
			Sleep(3000);
			break;
		case 4:
			continueGame = false;
			break;
		default:
			cout << "Неверный номер! Попробуйте снова\n"; Sleep(2000);
			cin.clear(); cin.ignore(32767, '\n');  // очищает буфер
			choice = NULL;
			break;
		}
	}
}

void Game::StartAdventure()
{
	int count = 0;
	while (true)
	{
		system("cls");
		if (count == 0)
		{
			string str = "A ты не из робкого десятка!\nЕсли коротко, то тебе нужно найти выход и не сдохнуть.\nСправишься? Смотри, я на тебя поставил, не разочаруй меня!\n\n";
			WriteText(str, 50);
		}
		cout << "Ты стоишь посреди глуши. Твои дальнейшие действия?\n\n" <<
				"1. Идём на Север\n" <<
				"2. Идём на Восток\n" <<
				"3. Идём на Юг\n" <<
				"4. Идём на Запад\n" <<
				"5. Никуда не идём. Куда нам торопится?\n";
			
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
	}
}

