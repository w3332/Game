#pragma once
#include "Function.h"

// ����� ��� ����������� �������� ������ (������� ����, ���� ��������, �������)
class Game
{
private:
	bool continueGame = true;

public:

	void FirstMessage();

	// ������� ����
	void StartScreen();

	// �������� ������� ����
	void StartAdventure();

};

