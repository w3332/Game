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

		string messageHelp = "Тут ничего сложного! Сам разберёшься по ходу дела!\n";

		short int choice = CheckingInput(1,4); 
		switch (choice) {
		case 1:
			StartAdventure();
			break;
		case 2:
			// << реализовать фаил загрузки
			break;
		case 3:
			WriteText(messageHelp, 30);
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
		//if (count == 0) FirstMessage();
		
		cout << "Ты стоишь посреди глуши. Твои дальнейшие действия?\n\n" <<
				"1. Идём на Север\n" <<
				"2. Идём на Восток\n" <<
				"3. Идём на Юг\n" <<
				"4. Идём на Запад\n" <<
				"5. Никуда не идём. Куда нам торопится?\n";
			
		int choice = CheckingInput(1,5);
		Monster mon(SelectMonster());
		switch (choice)
		{
		case 1:
			
			CollisionMonster(mon,player);
			//DealDamage(DamageToCharacter())// << добавить реализацию кейсов
			break;
		case 2:

			CollisionMonster(mon, player);
			//DealDamage(DamageToCharacter())// << добавить реализацию кейсов
			break;
		case 3:

			CollisionMonster(mon, player);
			//DealDamage(DamageToCharacter())// << добавить реализацию кейсов
			break;
		case 4:

			CollisionMonster(mon, player);
			
			//DealDamage(DamageToCharacter())// << добавить реализацию кейсов
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
		if (player.GetLevel() >= 10) {
			
			WriteText(" вы красавчик, вы победили", 20);
			break;
		}
		system("pause");
	}

}

