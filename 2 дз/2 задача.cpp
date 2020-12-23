//задача 2 вычислить функцию: В случае если |x|<1, то w вычисляется по формуле: a * ln|x|, если же |x|>=1, то по формуле: sqrt(a-x^2)
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <windows.h>
#include <cmath>

using namespace std;

int main()
{
SetConsoleCP(1251); //локализируем консоль
SetConsoleOutputCP(1251);
//вводим переменные
double w;
double x;
double a;
//сообщаем пользователю уравнения и просим ввести переменные
cout << "В случае если |x|<1, то w вычисляется по формуле: a * ln|x|, если же |x|>=1, то по формуле: sqrt(a-x^2)" << endl;
cout << "Введите число x" << endl;
cin >> x;
cout << "Введите число a" << endl;
cin >> a;
//делаем проверку согласно условию задачи, и в зависимости от результата выводим ответ, либо сообщение об ошибке.
if (abs(x) < 1 && x != 0)
{
    w = a * log(abs(x));
    cout << "Ответ: " << w << endl;
}
else if (abs(x) >= 1 && a - pow(x,2) > 0)
{
    w = sqrt(a - pow(x,2));
    cout << "Ответ: " << w << endl;
}
else
{
    cout << "Введены некорректные данные" << endl;
}
    return 0;
}
