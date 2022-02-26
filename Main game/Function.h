#pragma once
#include <iostream>
#include <windows.h>

#include "Game.h"
#include "Character.h"
#include "Monster.h"
#include "Player.h"
using namespace std;

void WriteText(const string& text, int printSpeed);

MonsterType SelectMonster();

void Battle(Player play, Monster mon); 



