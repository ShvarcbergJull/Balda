#include <iostream>
#include <locale.h>
#include "player.h"

using namespace std;

Play rec(char a, Play p, char** pole) // ф-ия, которая смотрит стоит ли рядом следущая буква
{
	int r = 0;
	if (pole[p.i + 1][p.j] == a)
	{
		p.i += 1;
		return p;
	}
	if (pole[p.i][p.j + 1] == a)
	{
		p.j += 1;
		return p;
	}
	if (pole[p.i - 1][p.j] == a)
	{
		p.i -= 1;
		return p;
	}
	if (pole[p.i][p.j - 1] == a)
	{
		p.j -= 1;
		return p;
	}
	return p;
}

void game(char** pole, int m, int m1)
{
	setlocale(LC_ALL, "Russian");
	char* a = new char[25]; // массив для слова, которое будет вводить пользователь
	Play mass[4]; // массив, предусматривающий те случаи, когда начальная буква встречается несколько раз на поле игры
	cout << "Введите слово: ";
	cin >> a;

	if (*a == 'r') {
		cout << "Спасибо за игру!" << endl;
		cout << "Ваш результат: " << m1 << "/" << m << endl;
		return;
	}

	m++; // подсчёт общего количества ходов

	int n = 0;
	for (int i = 1;i < 6;i++) // поиск первой буквы на поле
		for (int j = 1;j < 6;j++)
			if (*a == pole[i][j]) {
				mass[n].i = i;
				mass[n].j = j;
				n++;
			}
	if (n == 0) 
	{
		cout << "Такого слова нет!" << endl;
		game(pole, m, m1);
		return;
	}

	a++;
	int k = 0, sh = 1;
	while (*a != 0) // проверка последующих букв слова
	{
		Play pr = rec(*a, mass[k], pole); // возращается изменённая структура
		if (pr.i == mass[k].i && pr.j == mass[k].j) // проверка, изменилась ли структура
			if (sh == 1) // проверка, проверяется вторая буква или какая то другая
				if (k != n) // проверка всех начальных букв на поле
				{
					k++;
					continue;
				}
				else
					break;
			else
				break;
		mass[k] = pr;
		sh++;
		a++;
	}
	if (*a == 0)
	{
		cout << "Такое слово есть:)" << endl;
		m1++; // подсчёт правильных ходов
		game(pole, m, m1);
		return;
	}
	cout << "Такого слова нет!" << endl;
	game(pole, m, m1);
	return;
}
