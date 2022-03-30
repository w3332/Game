#pragma once
#include "Function.h"
#include "Player.h"
#include "Monster.h"
#include"Item.h"

// класс для отображения игрового экрана (главное меню, меню действий, диалоги)
class Game
{
private:
	bool continueGame = true;
	short int choice = 0; // используем везде где предоставляем выбор игроку
	Player player;
public:
	// главное меню
	void StartScreen();

	// возвращает true если выполнено одно из условий окончания игры
	bool EndGame();

	// основное игровое окно
	void StartAdventure();

	// окно столкновения с монстром
	void CollisionMonster();

	// окно сражения с монстром
	void Battle(Monster& mon);
};

