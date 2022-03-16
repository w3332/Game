#pragma once
#include <iostream>
#include <windows.h>

#include "Game.h"
#include "Character.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

//имитирует в консоли печать текста вручную
void WriteText(const string& text, int printSpeed);

// проверяет корректность ввода;
int CheckingInput(int minValue, int maxValue);

// рандомно выбирает монстра
MonsterType SelectMonster();

void CollisionMonster(Monster &mon, Player &plr);

void Battle(Monster &mon, Player &plr);



