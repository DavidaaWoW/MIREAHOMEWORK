//задача "шарики" - Сюжет задачи про шарики. Из урны с 10 пронумерованными шариками вынимают по одному шарику. Подсчитать общее количество ситуаций, когда номер хотя бы одного вынутого шарика совпадает с порядковым номером действия "вынимания", например, когда шарик № 3 будет вынут 3-им по порядку.
#include <iostream>
#include <vector>

using namespace std;

//вводим глобальные переменные
int numbers[10];
int counter = 0;
vector <int> arr(20);

void perestanovka(int a, int b) //вводим функцию перестановку, которая переставляет местами элементы массива
{
	int t = numbers[a];
	numbers[a] = numbers[b];
	numbers[b] = t;
}

void func(int m, int N) //функция, которая ничего не возвращает, а внутри себя считает количество возможных перестановок
{
	if (m == N) //если комбинации ещё не было, запускаем этот процесс
	{
			for (int i = 0; i < N; i++)
                {
				arr[i] = numbers[i];
                }
			for (int j = 0; j < arr.size(); j++)
			{
				if (arr[j] == j + 1)
				{
					counter += 1;
					break;
				}
			}
		}
	else //если же была, то выполняем перестановку
	{
		for (int j = m; j < N; j++)
		{
			perestanovka(m, j);
			func(m + 1, N);
			perestanovka(m, j);
		}
	}
}

int main()
{
	int N = 10;
	for (int i = 0; i < N; i++)
    {
		numbers[i] = i + 1;
    }
	func(0, N); //вызываем функцию
	cout << counter << endl; //выводим результат
	return 0;
}
