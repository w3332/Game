#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

//имитирует печать текста вручную, printSpeed - скорость печати каждого символа в миллисекундах
void WriteText(const string& text, int printSpeed);

// проверяет корректность ввода в указанном диапазоне;
int CheckingInput(const int minValue,const int maxValue);





