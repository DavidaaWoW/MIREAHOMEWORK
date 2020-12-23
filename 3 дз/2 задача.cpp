/*2 задача - «Ссуда». Под какой процент p выдана ссуда величиной S рублей, которая гасится месячными выплатами величиной m в течение n лет. Формула приведена в предыдущей задаче.
r из формулы выразить невозможно, поэтому пользуемся методом подбора
*/
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
setlocale (LC_ALL, "Russian"); //локализируем консоль
float r,m,S,n,a,p,f; //вводим переменные
r = 0.2; //выбираем случайное значение r, с которым в дальнейшем будем сравнивать получившееся значение
//сообщаем пользователю уравнение и просим ввести переменные
cout << "Базовое уравнение:m = (Sr(1+r)^n) / (12((1+r)^n - 1)), r = p / 100" << endl;
cout << "Введите числа m,S и n" << endl;
cin >> m >> S >> n;
//используя переменные и случайное число r вычисляем число a
a = (S * r * pow(1+r,n)) / (12 * (pow(1+r,n) - 1));
//вычисляем разность f - число по модулю, разность между ожидаемым m и фактическим a
f = abs(m - a);
if (f < 0.001) //если очень повезло, и мы сразу угадали ответ - выводим его, можно также играться с требуемой точностью
{
    p = r * 100;
    cout << "Процент p равен: " << p << "%" << endl;
    return 0;
}
else
{
    for (r = 0.01; r < 1; r += 0.00001) //в случае, если погрешность между фактическим и требуемым значением превышает заданное значение - начинаем поиск постепенно изменяя случайное число r, опять подставляя и сравнивая, при более низкой точности программа выполняется быстрее, но есть шанс того, что она не найдёт в диапазоне проверки нужное значение
    {
        a = (S * r * pow(1+r,n)) / (12 * (pow(1+r,n) - 1));
        f = abs(m - a);
        if (f < 0.001)
        {
            p = r * 100;
            cout << "Процент p равен: " << p << "%" << endl;
            return 0;
        }
    }
}
//если программа дошла до этого момента - значит она не смогла найти ответ.
    cout << "Неправильно введены данные";
    return 0;
}
