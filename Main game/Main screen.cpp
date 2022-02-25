#include "Function.h"
#include "Game.h"
#include"Player.h"
#include"Monster.h"
#include"Character.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	srand(time(NULL));
	rand(); // холостой прогон, не удалять!

	system("mode con cols=100 lines=25"); // РАЗМЕР ОКНА
	system("color 0E");/* 
	Атрибуты цветов задаются в виде ДВУХ шестнадцатеричных цифр -
	первая задает цвет фона, а вторая определяет цвет текста. 
	Каждая цифра может иметь следующие значения:

	0 = Черный  8 = Серый
	1 = Синий	9 = Светло-синий
	2 = Зеленый A = Светло-зеленый
	3 = Голубой B = Светло-голубой
	4 = Красный C = Светло-красный
	5 = Лиловый D = Светло-лиловый
	6 = Желтый  E = Светло-желтый
	7 = Белый   F = Ярко-белый
	*/

	const int SIZE = 3;
	string welcome = "Добро пожаловать в игру!\nЯ вижу тебе явно заняться нечем...\nНу что ж, давай сыграем!";
	
	WriteText(welcome, 40);

	Game game;
	
	
	game.StartScreen();

	return 0;
}