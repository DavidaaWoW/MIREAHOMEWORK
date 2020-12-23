#include <iostream>
#include <math.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
SetConsoleOutputCP(1251); //локализуем консоль
//вводим переменные
double h;
double R;
double r;
double l;
double V;
double S;
//сообщаем пользователю уравнения и просим ввести значения
cout << "Уравнение объёма V = 1 / 3 * pi * h * (R^2 + R * r + r^2) и площади полной поверхности S = pi * (R^2 + (R + r) * l + r^2) усечённого конуса." << endl;
cout << "Введите число h" << endl;
cin >> h;
cout << "Введите число R" << endl;
cin >> R;
cout << "Введите число r" << endl;
cin >> r;
cout << "Введите число l" << endl;
cin >> l;
if (R > 0 && r > 0 && h > 0 && l > 0 && R > r && l > h && l * l == h * h + pow(R-r,2)) //проверяем все необходимые условия, и в случае, если возможен физический аналог с введёнными размерами, высчитываем объём и площадь
{
    V = M_PI * h * (pow(R,2) + R * r + pow(r,2)) / 3;
    S = M_PI * (pow(R,2) + (R + r) * l + pow(r,2));
    cout << "Ответ: V = " << V << " S = " << S <<endl;
}
else //В противном случае выводим сообщение об ошибке
{
    cout << "Введены неправильные данные, невозможно существование физического эквивалента" << endl;
}
    return 0;
}
