#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

#define DEBUG 0 // ��� ������� ������� ������ - 0, ��� ������ ������ - 1 >> ������������� � ����� Function.h <<

//��������� ������ ������ �������, printSpeed - �������� ������ ������� ������� � �������������
void WriteText(const string& text, int printSpeed);

// ��������� ������������ ����� � ��������� ���������;
int CheckingInput(const int minValue,const int maxValue);





