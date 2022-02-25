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
	rand(); // �������� ������, �� �������!

	system("mode con cols=100 lines=25"); // ������ ����
	system("color 0E");/* 
	�������� ������ �������� � ���� ���� ����������������� ���� -
	������ ������ ���� ����, � ������ ���������� ���� ������. 
	������ ����� ����� ����� ��������� ��������:

	0 = ������  8 = �����
	1 = �����	9 = ������-�����
	2 = ������� A = ������-�������
	3 = ������� B = ������-�������
	4 = ������� C = ������-�������
	5 = ������� D = ������-�������
	6 = ������  E = ������-������
	7 = �����   F = ����-�����
	*/

	const int SIZE = 3;
	string welcome = "����� ���������� � ����!\n� ���� ���� ���� �������� �����...\n�� ��� �, ����� �������!";
	
	WriteText(welcome, 40);

	Game game;
	
	
	game.StartScreen();

	return 0;
}