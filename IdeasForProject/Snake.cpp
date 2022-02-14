//#include <iostream>
//#include <conio.h>
//#include <Windows.h>
//using namespace std;
//
//bool game_over;
//const int width = 20;
//const int height = 20;
//
//// координаты игрока(головы)
//int x, y;
//int score = 0;
//
//// длина и координаты хвоста
//int cTail = 0, tailX[width * height], tailY[width * height];
//
//// координаты еды
//int objectX, objectY;
//
//// направление движения
//enum Direction
//{
//	STOP = 0,
//	LEFT,
//	RIGHT,
//	UP,
//	DOWN
//};
//
//Direction dir;
//
//// меню настроек по умолчанию
//void Setup()
//{
//	game_over = false;
//	dir = STOP;
//	objectX = rand() % (width - 1) + 1;
//	objectY = rand() % (height - 1) + 1;
//	x = rand() % (width - 1) + 1;
//	y = rand() % (height - 1) + 1;
//	score = 0;
//
//}
//
//// прорисовывает игровое поле
//void Paint()
//{
//	// функция, которая очищает консоль
//	system("cls");
//
//	for (int i = 0; i < width + 1; i++) { cout << "#"; }
//	cout << "\n";
//
//	for (int i = 0; i < height; i++)
//	{
//		for (int j = 0; j < width; j++)
//		{
//			if (j == 0 || j == width - 1)
//				cout << "#";
//
//			if (i == y && j == x)
//				cout << "@";
//			else if (i == objectY && j == objectX)
//				cout << "*";
//			else {
//				bool checkTail = false;
//				for (int k = 0; k < cTail; k++) {
//					if (tailX[k] == j && tailY[k] == i)
//					{
//						cout << "o";
//						checkTail = true;
//					}
//				}
//				if (!checkTail)
//					cout << " ";
//			}
//
//		}
//		cout << "\n";
//
//	}
//
//
//	for (int i = 0; i < width + 1; i++) { cout << "#"; }
//	cout << "\n";
//	cout << "\n" << "Score = " << score << "\n";
//}
//
//// меняет направление движения в зависимости от нажатой клавиши
//void Input()
//{
//	// _kbhit - true если кнопка нажата, _getch - возвращает символ соответственно нажатой кнопки
//	if (_kbhit())
//	{
//		switch (_getch())
//		{
//		case 'a':
//			dir = LEFT;
//			break;
//		case 'w':
//			dir = UP;
//			break;
//		case 'd':
//			dir = RIGHT;
//			break;
//		case 's':
//			dir = DOWN;
//			break;
//		case 'x':
//			game_over = true;
//			break;
//		}
//	}
//
//}
//
//// основные механики игры
//void Logic()
//{
//	int prevX = tailX[0];
//	int prevY = tailY[0];
//	int prev2Y, prev2X;
//	tailX[0] = x;
//	tailY[0] = y;
//
//	// сохраняет коордианты хвоста для последующей прорисовки
//	for (int i = 1; i < cTail; i++)
//	{
//		prev2X = tailX[i];
//		prev2Y = tailY[i];
//		tailX[i] = prevX;
//		tailY[i] = prevY;
//		prevX = prev2X;
//		prevY = prev2Y;
//	}
//
//	// отвечает за движение
//	switch (dir)
//	{
//	case LEFT:
//		--x;
//		break;
//	case RIGHT:
//		++x;
//		break;
//	case UP:
//		--y;
//		break;
//	case DOWN:
//		++y;
//		break;
//	}
//
//	// проигрываем если сталкиваемся со стеной
//	//if (x > width-2 || y > height-1 || x <0 || y <0)
//	//{
//	//	game_over = true;
//	//}
//
//	// при сталкивание со стеной переносит на противоположную сторону
//	if (x >= width)
//		x = 0;
//	else if (x < 0)
//		x = width - 2;
//
//	if (y >= height)
//		y = 0;
//	else if (y < 0)
//		y = height - 1;
//
//	// проигрываем если сталкиваемся с хвостом
//	for (int i = 0; i < cTail; i++)
//	{
//		if (x == tailX[i] && y == tailY[i])
//			game_over = true;
//	}
//
//	// когда съедаем объект
//	if (x == objectX && y == objectY)
//	{
//		++score;
//		++cTail;
//		objectX = rand() % width;
//		objectY = rand() % height;
//	}
//}
//
//
//int main()
//{
//	srand(time(NULL));
//
//	// сбрасываем рандом
//	int rd = rand();
//
//	// немного ускоряет работу cout
//	std::ios::sync_with_stdio(false);
//
//	Setup();
//
//	while (!game_over)
//	{
//		Input();
//		Logic();
//		Paint();
//
//		Sleep(200);
//	}
//
//	cout << "Game over!" << endl;
//
//	return 0;
//}