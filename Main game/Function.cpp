#include "Function.h"

void WriteText(const string& text, int printSpeed)
{
	Sleep(500);
	for (char var : text)
	{
		if (var == ' ')
			Sleep(printSpeed + 20);
		cout << var;
		Sleep(printSpeed);
	}
	Sleep(500);
}

MonsterType SelectMonster() {

	MonsterType type = MonsterType(rand() % MonsterType::MAX);
	return type;
}

void Battle(Player play, Monster mon)
{
	
}
