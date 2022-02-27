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

void Battle(Player play, Monster mon)
{
	
}
