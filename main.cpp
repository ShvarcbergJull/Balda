#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"

using namespace std;

ostream& operator <<(ostream& cout, char** m)
{
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++)
			cout << m[i][j] << ' ';
		cout << endl;
	}
	return cout;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char** cow = new char*[7];
	for (int i = 0; i < 7; i++)
		cow[i] = new char[7];
	char* a = new char[25];

	cout << "Игра БАЛДА" << endl;
	cout << "Правила: Дано поле посредине которого написано слово БАЛДА, а вокруг него буквы, нужно найти слова." << endl;
	cout <<	"Если вы хотите выйти из игры, напишите: r." << endl;

	srand(time(0));
	char arr[] = "BALDA";
	char* pa = arr;
	for (int i = 0; i < 7; i++)
	{
		cow[0][i] = ' ';
		cow[6][i] = ' ';
		cow[i][0] = ' ';
		cow[i][6] = ' ';
	}
	for (int i = 1; i < 6; i++)
		if (i != 3)
			for (int j = 1; j < 6; j++)
				cow[i][j] = 'A' + rand() % ('Z' - 'A' + 1);
		else {
			for (int j = 1;j < 6;j++)
			{
				cow[i][j] = *pa;
				pa++;
			}
		}
	cout << cow << endl;

	int  win = 0, count = 0;

	game(cow, count, win);

	system("pause");
	return 0;
}
