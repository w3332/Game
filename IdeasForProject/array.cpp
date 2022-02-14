//#include <iostream>
//using namespace std;
//
//int main()
//{
//	const int width = 40, height = 30;
//	char arr[height][width];
//
//	// заполняем массив
//	for (size_t i = 0; i < height; i++)
//	{
//		for (size_t j = 0; j < width; j++)
//		{
//			if (i == 0 || i == height - 1)
//				arr[i][j] = '#';
//			else if (j == 0 || j == width - 1)
//				arr[i][j] = '#';
//			else
//				arr[i][j] = '.';
//		}
//	}
//
//	// выводим на экран
//	for (size_t i = 0; i < height; i++)
//	{
//		for (size_t j = 0; j < width; j++)
//		{
//			cout << arr[i][j];
//		}
//		cout << endl;
//	}
//
//	cout << arr << endl;
//}