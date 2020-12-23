//6 задача Декодировать римскую запись числа, состоящего из любого количества знаков.
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int correct_enter(string c) //функция проверки правильности ввода, получает введённую строку
{
    //выполняем действия для перевода из строки в символьный массив - более подробно описано в основной функции - main
    int a = c.length(); 
    char enter_c[a];
    strcpy(enter_c, c.c_str());
    char roman[] = {'I','V','X','L','C','D','M'};
    int k = 0; //вводим переменную счётчик, под конец сравниваем её с длинной массива, если они равны - то введенное число существует
    for (int i = 0; i<a;i++) // если хоть одно условие выполняется - от k отнимается единица, соответственно под конец оно не будет равно длинне массива, а значит введённое число некорректно
    {
    if(enter_c[i - 3] == 'I' && enter_c[i - 2] == 'I' && enter_c[i - 1] == 'I' && enter_c[i] == 'I') //сравниваем 4 подряд идущие I
        k -= 1;
    else if(enter_c[i] == 'X' && enter_c[i - 1] == 'X' && enter_c[i - 2] == 'X' && enter_c[i-3] == 'X') //сравниваем 4 подряд идущие X
        k -= 1;
    else if(enter_c[i] == 'C' && enter_c[i - 1] == 'C' && enter_c[i - 2] == 'C' && enter_c[i - 3] == 'C') //сравниваем 4 подряд идущие C
        k -= 1;
    else if(enter_c[i] == 'X' && enter_c[i - 1] == 'I' && enter_c[i - 2] == 'I') //проверка на IIX
        k -= 1;
    else if((enter_c[i] == 'X' || 'V' || 'C' || 'L' || 'D' || 'M') && (enter_c[i - 1] == 'X' || 'V' || 'L' || 'C' || 'D' || 'M') && (enter_c[i - 2] == 'I')) //проверка на IXX/iVV и т.д
        k -= 1;
    else if((enter_c[i] == 'V' && enter_c[i - 1] == 'V') || (enter_c[i] == 'L' && enter_c[i - 1] == 'L') || (enter_c[i] == 'D' && enter_c[i - 1] == 'D')) //проверка на VV, LL и DD
        k -= 1;
    else if((enter_c[i] == 'X' && enter_c[i - 1] == 'V') || (enter_c[i] == 'C' && enter_c[i - 1] == 'I') || (enter_c[i] == 'C' && enter_c[i - 1] == 'V') || (enter_c[i] == 'C' && enter_c[i-1] == 'L') || (enter_c[i] == 'L' && enter_c[i - 1] == 'I') || (enter_c[i] == 'L' && enter_c[i - 1] == 'V') || (enter_c[i] == 'D' && enter_c[i - 1] == 'I') || (enter_c[i] == 'D' && enter_c[i - 1] == 'X') || (enter_c[i] == 'D' && enter_c[i - 1] == 'L') || (enter_c[i] == 'D' && enter_c[i - 1] == 'V') || (enter_c[i] == 'M' && enter_c[i - 1] == 'I') || (enter_c[i] == 'M' && enter_c[i - 1] == 'V') || (enter_c[i] == 'M' && enter_c[i - 1] == 'X') || (enter_c[i] == 'M' && enter_c[i - 1] == 'L') || (enter_c[i] == 'M' && enter_c[i - 1] == 'D')) //очень большая проверка недопустимых пар из знаков
        k -= 1;
    else if(((enter_c[i] == 'V') && (enter_c[i - 1] == 'I') && (enter_c[i - 2] == 'V')) || ((enter_c[i] == 'L') && (enter_c[i - 1] == 'X') && (enter_c[i - 2] == 'L')) || ((enter_c[i] == 'D') && (enter_c[i - 1] == 'C')) && (enter_c[i - 2] == 'D')) //проверка на VIV, LXL и DCD
        k -= 1;
    else //если ни одно из условий не выполняется начинаем проверку на принадлежность введённых символов к допустимому пулу римских символов
    {
        for(int j = 0; j<7; j++)
        {
    if(enter_c[i] == roman[j])
    {
        k += 1;
    }
        }
    }
    }
    if(k == a) //если переменная k равна длинне массива выводим единицу, если нет, то 0
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int count1(string d) //функция подсчёта
{
    //опять выполняем процедуру перевода строки в символьный массив
    int a = d.length();
    char enter_c[a];
    strcpy(enter_c, d.c_str());
    int k = 0;
    //цикл длится до тех пор, пока не закончится число, приравниваем к символам и символьным комбинациям значения арабских цифр
    for (int i = 0; i < a; i++)
    {
    if (enter_c[i] == 'I')
        k += 1;
    else if(enter_c[i] == 'V')
        {
            if(enter_c[i - 1] == 'I')
                k += 3;
            else
                k += 5;
        }
    else if(enter_c[i] == 'X')
    {
        if(enter_c[i - 1] == 'I')
            k += 8;
        else
            k += 10;
    }
    else if(enter_c[i] == 'L')
        {
            if(enter_c[i-1] == 'X')
                k += 30;
            else
                k += 50;
        }
    else if(enter_c[i] == 'C')
{
    if(enter_c[i-1] == 'X')
        k += 80;
    else
        k += 100;
}
    else if(enter_c[i] == 'D')
        {
            if(enter_c[i-1] == 'C')
            k += 300;
            else
            k += 500;
        }
    else if(enter_c[i] == 'M')
{
    if(enter_c[i-1] == 'C')
        k += 800;
    else
        k += 1000;
}
    }
    //как только она проходит свой случай к переменной добавляется нужное число, в конце просто возвращаем - что получилось
    return k;
}
int main()
{
    setlocale(LC_ALL, "Russian"); //локализируем консоль
    char roman[] = {'I','V','X','L','C','D','M'}; //вводим пул из используемых римских цифр
    string enter; //переменная ввода
    //сообщаем пользователю условия задачи и просим ввести римское число
    cout << "Введите римскую запись числа для её декодирования" << endl;
    cin >> enter;
    int a = enter.length(); //целочисленная переменная а - длинна введённого числа
    char enter_c[a]; //символьный массив длинны введённого числа
    strcpy(enter_c, enter.c_str()); //переносим в сивмольный массив строку
    if(correct_enter(enter) == 1) //если проверка показала, что число введено правильно - вызываем функцию подсчёта
    {
        count1(enter);
        cout << count1(enter);
    }
    else //в противном случае выводим сообщение об ошибке
    {
        cout << "Неправильная последовательность чисел!" << endl;
    }

    return 0;
}
