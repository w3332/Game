#pragma once
#include <map>

#include "Character.h"
#include "Function.h"

class Player : public Character
{
private:
	int level, exp ,expMax;
	std::map<std::string, int> backpack;
public:
	Player();
	
	// ����������� �����
	void Experience(int expr);

	// �������� ��� �� � ���������
	void PutInBackpack(std::string itemname);

	// ���������� ���������
	void LookInBackpack();

	void SetName (std::string name) { this->name = name; }
	int GetLevel() { return level;}

};



