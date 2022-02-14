//#include <iostream>
//#include <conio.h>
//#include <Windows.h>
//using namespace std;
//
//bool game_over;
//const int width = 20;
//const int height = 20;
//
//// ���������� ������(������)
//int x, y;
//int score = 0;
//
//// ����� � ���������� ������
//int cTail = 0, tailX[width * height], tailY[width * height];
//
//// ���������� ���
//int objectX, objectY;
//
//// ����������� ��������
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
//// ���� �������� �� ���������
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
//// ������������� ������� ����
//void Paint()
//{
//	// �������, ������� ������� �������
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
//// ������ ����������� �������� � ����������� �� ������� �������
//void Input()
//{
//	// _kbhit - true ���� ������ ������, _getch - ���������� ������ �������������� ������� ������
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
//// �������� �������� ����
//void Logic()
//{
//	int prevX = tailX[0];
//	int prevY = tailY[0];
//	int prev2Y, prev2X;
//	tailX[0] = x;
//	tailY[0] = y;
//
//	// ��������� ���������� ������ ��� ����������� ����������
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
//	// �������� �� ��������
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
//	// ����������� ���� ������������ �� ������
//	//if (x > width-2 || y > height-1 || x <0 || y <0)
//	//{
//	//	game_over = true;
//	//}
//
//	// ��� ����������� �� ������ ��������� �� ��������������� �������
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
//	// ����������� ���� ������������ � �������
//	for (int i = 0; i < cTail; i++)
//	{
//		if (x == tailX[i] && y == tailY[i])
//			game_over = true;
//	}
//
//	// ����� ������� ������
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
//	// ���������� ������
//	int rd = rand();
//
//	// ������� �������� ������ cout
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