#include "Function.h"

void WriteText(const string& text, int printSpeed)
{
	Sleep(printSpeed * 10);
	for (char var : text)
	{
		if (var == ' ' or var == '.' or var == '!')
			Sleep(printSpeed*3);
		cout << var;
		Sleep(printSpeed);
	}
	Sleep(printSpeed * 10);
}

int CheckingInput(int minValue, int maxValue)
{
	short int value;
	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
		{
			cin.ignore(32767, '\n');
			if (value >= minValue && value <= maxValue)
				return value;
		}
		cout << "Неверная команда! Попробуй снова: ";
	}
}
