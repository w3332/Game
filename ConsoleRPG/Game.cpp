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
	cout << "Гид: \"Пожалуйста представься, путник!\"\n" << "(введите ваше имя): ";
	getline(cin, name);
	character.initliaze(name);
	cout << "Гид: \"""Однако, забавное у Вас имя, " << name << "!\"" << endl;
}

void Game::mainMenu()
{	
	cout << "+++Главное меню+++\n\n" << 
		"1. Меню 1\n" << "2. Меню 2\n" << "3. Меню 3\n" << 
		"Ваши дальнейший действия? " << std::endl;
	cin >> choice;

	switch (choice)
	{
	case 1: // действие меню 1
		break;
	case 2: // действие меню 2
		break;
	case 3: // действие меню 3
		break;
	default:
		break;
	} 
} 
