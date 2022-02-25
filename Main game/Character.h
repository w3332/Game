#pragma once
#include <iostream>
#include"Function.h"

class Character
{
public:
	bool CheckLife();
	void GetDamage(Character&unit);
	

protected:
	int health,damage,defence;
	std::string name;



};


