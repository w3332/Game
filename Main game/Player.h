#pragma once
#include<iostream>
#include "Character.h"
#include"Monster.h"
#include"Function.h"

class Player : public Character
{
public:

	// ����� ������ ����������
	Player();
	void LevelUp();

private:
	//���������
	int level,expMax,exp;

};


