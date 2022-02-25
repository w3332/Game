#pragma once
#include<iostream>
#include "Character.h"
#include"Monster.h"
#include"Function.h"

class Player : public Character
{
public:

	// здесь только объ€влени€
	Player();
	void LevelUp();

private:
	//инвентарь
	int level,expMax,exp;

};


