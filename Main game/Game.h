#pragma once
#include "Function.h"
#include "Player.h"
#include "Monster.h"
#include"Item.h"

// ����� ��� ����������� �������� ������ (������� ����, ���� ��������, �������)
class Game
{
private:
	bool continueGame = true;
	short int choice = 0; // ���������� ����� ��� ������������� ����� ������
	Player player;
public:
	// ������� ����
	void StartScreen();

	// ���������� true ���� ��������� ���� �� ������� ��������� ����
	bool EndGame();

	// �������� ������� ����
	void StartAdventure();

	// ���� ������������ � ��������
	void CollisionMonster();

	// ���� �������� � ��������
	void Battle(Monster& mon);
};

