#pragma once
#include <iostream>
#include<vector>

using namespace std;
enum Rare {
	NORMAL,
	MEDIUM,
	RARE,
	LEGENDARY,
	MITHIC,
	MAXRAREITEM
};

class Item
{ 
protected: 
	vector<string>  AllItems{
		"������","�������� �����","������"
	};
	// ���� �������� ������� �������� if � ������� Player::WhatItemDoing
public:
	string RandomItem();

};


