#pragma once
#include <iostream>
#include <windows.h>
#include"Monster.h"
#include"Player.h"
#include"Character.h"
using namespace std;

void WriteText(const string& text, int printSpeed);


MonsterType SelectMonster();

void Battle(Player play, Monster mon); 



