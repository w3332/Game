#pragma once
#include <iostream>
#include <windows.h>

#include "Game.h"
#include "Character.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

#define DEBUG 0 // 0 - ��� ��������� �������, 1 - ��� �����-������

//��������� � ������� ������ ������ �������
void WriteText(const string& text, int printSpeed);

// ��������� ������������ �����;
int CheckingInput(int minValue, int maxValue);

// �������� �������� �������
MonsterType SelectMonster(int level);

void CollisionMonster(Monster &mon, Player &plr);

void Battle(Monster &mon, Player &plr);

int CheckHealth(int hp);

