#include <iostream>
#include <Windows.h>

#include "Game.h"

using namespace std;

Game::Game()
{
	choice = 0;
	playing = true;
}

Game::~Game()
{
}


void Game::setName()
{
	string name;
	cout << "���: \"���������� �����������, ������!\"\n" << "(������� ���� ���): ";
	getline(cin, name);
	character.initliaze(name);
	cout << "���: \"""������, �������� � ��� ���, " << name << "!\"" << endl;
}

void Game::mainMenu()
{	
	cout << "+++������� ����+++\n\n" << 
		"1. ���� 1\n" << "2. ���� 2\n" << "3. ���� 3\n" << 
		"���� ���������� ��������? " << std::endl;
	cin >> choice;

	switch (choice)
	{
	case 1: // �������� ���� 1
		break;
	case 2: // �������� ���� 2
		break;
	case 3: // �������� ���� 3
		break;
	default:
		break;
	} 
} 
