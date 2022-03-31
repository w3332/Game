#pragma once
#include <map>
#include <vector>

#include "Character.h"
#include "Function.h"

class Player : public Character
{
private:
	int level, exp ,expMax;
	map<string, int> backpack;
public:
	Player();
	
	// ����������� �����
	void Experience(int expr);

	// �������� ��� �� � ���������
	void PutInBag(string itemname);

	// ���������� ���������
	void LookInBag();

	// ������� ������� �� ���������, ������� ����������
	void CheckItem();

	// ���������� true ���� � ��������� ��� �� ����
	bool AnythingInBag();

	// ���������� ������ ������������ ������� �� ���������
	void UseItem();

	// ��������� ������� �� ���������
	void WhatItemDoes(string itemName);

	void SetName (string name) { this->name = name; }
	int GetLevel() { return level;}
};



