#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

#define DEBUG 0 // для быстрой отладки ставим - 0, для полной версии - 1 >> редактировать в файле Function.h <<

//имитирует печать текста вручную, printSpeed - скорость печати каждого символа в миллисекундах
void WriteText(const string& text, int printSpeed);

// проверяет корректность ввода в указанном диапазоне;
int CheckingInput(const int minValue,const int maxValue);





