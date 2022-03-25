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
				"\nВыбери пункт меню: ";

		choice = CheckingInput(1,4); 
		switch (choice) 
		{
		case 1:
			StartAdventure();
			break;
		case 2:
			// реализовать фаил загрузки
			break;
		case 3:
			WriteText("Тут ничего сложного! Сам разберёшься по ходу дела!\n", 30);
			// создать раздел FAQ или базу знаний
			system("pause");
			break;
		case 4:
			continueGame = false; // завершаем игру
			break;
		default:
			break;
		}
		Player newplayer;
		player = newplayer; // пересоздаём игрока
	}
}

bool Game::EndGame()
{
	if (player.IsDead())
	{
		WriteText("Вы погибли! Приключение окончено.", 40);
		Sleep(2000);
		return true;
	}
	else if (player.GetLevel() >= 10)
	{
		WriteText("Поздравляем! Вы достигли 10 уровня,и теперь вы самый крутой перчик на районе!\n.", 40);
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
	while (!(Game::EndGame())) // пока не выполнено одно из условий окончания игры
	{
		system("cls"); // очищает экран консоли
		
		cout << "Ты стоишь посреди глуши. Нужно что то делать...\n\n" <<
				"Движение:\n" <<
				" 1. на Север\n" <<
				" 2. на Восток\n" <<
				" 3. на Юг\n" <<
				" 4. на Запад\n" <<
				"Информация:\n" <<
			    " 5. Инвентарь\n"<<
				"Прочее:\n"
				" 6. Закончить игру\n\n" <<
				"Твои дальнейшие действия: ";

		choice = CheckingInput(1,6);
		switch (choice)
		{
		case 1:
			// Y++
			CollisionMonster(); // <--- для тестирования
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
			player.LookInBackpack(); // смотрим в инвентарь
			break;
		case 6:
			return; // выход
		default:
			break;
		}
		
	}

}

void Game::CollisionMonster()
{
	Monster mon(Monster::SelectMonster());
	cout << "\nПеред вами появился " << mon.GetName() <<
		"\nУ вас есть выбор:\n" <<
		" 1. Сражаться\n" <<
		" 2. Попробовать сбежать\n\n" <<
		"Ваши дальнейшие действия: ";
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
				cout << " Вам удалось сбежать!\n";
				system("pause");
			}
			else
			{
				int damageMon = player.DamageReceived(mon) * 1.5; // рассчитываем урон по игроку при неудачной попытке
				cout << "Вам не удалось сбежать! " << mon.GetName() << " нанёс вам " << damageMon << " урона.\n";
				player.ReducedHealth(damageMon);
				cout << "Сражение уже не получится избежать. Придётся драться...\n";
				system("pause"); // ставим на паузу перед началом боя
				Battle(mon);
			}
		}
	
}

void Game::Battle(Monster& mon)
{
	while (!(player.IsDead())) // пока игрок не умер или не повержен монстр
	{
		system("cls"); // очищает экран консоли
		int damageMon = player.DamageReceived(mon);
		int damagePlr = mon.DamageReceived(player);

		WriteText("Вы идёте в атаку и наносите ", 0);
		cout << damagePlr << " урона" << endl;
		mon.ReducedHealth(damagePlr);
		WriteText("текущее здоровье монстра ", 0);
		cout << mon.GetHealth() << "\n\n";

		if (mon.IsDead()) {
			WriteText("Бой окончен.\n\n", 40);
			player.Experience(mon.GetExperience());//получаем опыт 
			Buff randitem(Buff::SelectBuff()); // создаём рандомный расходник и передаём его игроку
			player.PutInBackpack(randitem.GetName());
			break;
		}
		else {
			cout << mon.GetName() << " нанёс вам " << damageMon << " урона" << endl;
			player.ReducedHealth(damageMon);
			WriteText("Ваше текущее здоровье = ", 0);
			cout << player.GetHealth() << endl;
		}
		system("pause");
	}
}

