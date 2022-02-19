#include <iostream>
#include <windows.h>

#include "Game.h"
#include "Character.h"

using namespace std;

int main()
{
	// Русификатор
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));
	rand(); // холостой прогон, не удалять!

	Game game;
	game.setName();

	while (game.getPlaying())
	{
		game.mainMenu();
	}

	return 0;
} //end main