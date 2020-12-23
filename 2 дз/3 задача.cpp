//3 задача «Функция». Для произвольных x, y и b вычислить функцию z = ln(b - y) * sqrt(b - x)
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251); //локализируем консоль
SetConsoleOutputCP(1251);
//вводим переменные
double z;
double x;
double y;
double b;
//сообщаем пользователю уравнение функции и просим ввести значения
cout << "Базовое уравнение функции z = ln(b - y) * sqrt(b - x)" << endl;
cout << "Введите число b" << endl;
cin >> b;
cout << "Введите число y" << endl;
cin >> y;
cout << "Введите число x" << endl;
cin >> x;
//согласно свойствам корня и натурального логарифма делаем проверку на правильность введённых данных, и в зависимости от результата выводим ответ, или сообщение об ошибке
if (b - y > 0 && b - x >= 0)
{
    z = log(b - y) * sqrt(b - x);
    cout << "Ответ: z = " << z << endl;
}
else
{
    cout << "Введённые данные некорректны" << endl;
}
    return 0;
}
