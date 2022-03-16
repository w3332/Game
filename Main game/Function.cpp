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

MonsterType SelectMonster() {

	MonsterType type = MonsterType(rand() % MonsterType::MAX);
	return type;
}

void CollisionMonster(Monster &mon,Player &plr)
{

	cout << "перед вами появился " << mon.GetName() << endl;
	cout << "ваши дальнейшие действия:" << endl;
	cout << "1.Сражаться" << endl << "2.Сбежать" << endl;
	int g = CheckingInput(1, 2);
	if (g == 1) {

		Battle(mon,plr);
	}
	

}

void Battle(Monster &mon, Player &plr)
{
	while(true) {
		int damageMon = plr.DamageToCharacter(mon);
		int damagePlr = mon.DamageToCharacter(plr);
		cout << "вы идёте в атаку и наносите " << damagePlr << " урона" << endl;
		mon.DealDamage(damagePlr);
		WriteText("текущее здоровье монстра ", 20);
		cout  << mon.GetHealth() << endl;

		if (mon.CheckLife()) {
			plr.LevelUp(mon.GetType());//получаем опыт 
			break;

		}
		else  {
			cout << mon.GetName() << " нанёс вам " << damageMon << " урона" << endl;
			plr.DealDamage(damageMon);
			WriteText("ваше текущее здоровье = ", 20);
			
			cout  << plr.GetHealth() << endl;

		}

		if (plr.CheckLife()) {
			break;
		}


		system("pause");
	}
}
