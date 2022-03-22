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
		std::cout << "Неверная цифра! Попробуй снова: ";
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

	cout << "\nПеред вами появился " << mon.GetName() <<
			"\nВаши дальнейшие действия:\n" <<
			"1.Сражаться\n" <<
			"2.Сбежать\n\n";
	int g = CheckingInput(1, 2);
	if (g == 1) {

		Battle(mon,plr);
	}
	else if (g == 2) {
		int q = rand() % 2;
		if (q == 0) {
			cout << " Вам удалось сбежать " << endl;
	
		}
		else if (q == 1) {
			int damageMon = plr.DamageToCharacter(mon)*1.5;
			cout << " Вам не удалось сбежать. " << mon.GetName() << " нанёс вам " << damageMon << " урона " << endl;
			plr.DealDamage(damageMon);
			system("pause");
			Battle(mon, plr);
		}
		
	}
	

}

void Battle(Monster &mon, Player &plr)
{
	while(true) {
		system("cls"); // очищает экран консоли
		int damageMon = plr.DamageToCharacter(mon);
		int damagePlr = mon.DamageToCharacter(plr);

		WriteText("Вы идёте в атаку и наносите ", 20);
		cout<< damagePlr << " урона" << endl;
		mon.DealDamage(damagePlr);
		WriteText("текущее здоровье монстра ", 20);
        cout  << CheckHealth(mon.GetHealth()) << "\n\n";

		if (mon.CheckLife()) {
			plr.LevelUp(mon.GetType());//получаем опыт 
			//plr.AddToInventory();

			break;
		}
		else  {
			cout << mon.GetName() << " нанёс вам " << damageMon << " урона" << endl;
			plr.DealDamage(damageMon);
			WriteText("ваше текущее здоровье = ", 20);
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
