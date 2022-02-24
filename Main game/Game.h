#pragma once
#include "Function.h"

// класс для отображения игрового экрана (главное меню, меню действий, диалоги)
class Game
{
private:
	bool continueGame = true;
public:
	
	// главное меню
	void StartScreen();

	// основное игровое окно
	void StartAdventure();


};

