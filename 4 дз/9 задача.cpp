//9 задание
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <cstdlib>

using namespace std;

string func1(int l,int sys2) //функция перевода из десятичной системы исчисления в требуемую, получает на вход строку числа в 10 системе исчисления, и номер системы
{
    int f;
    string s;
        vector <int> num1; //так как нам нужно записывать значения с конца при делении легче воспользоваться вектором, а не массивом
        while(l>=sys2)
        {
            f = l%sys2; //записываем остаток
            num1.insert(num1.end(),f);
            l /= sys2; //делим число для продолжения цикла
        }
        num1.insert(num1.end(),1); //вставляем в начало числа единицу
        num1.pop_back();
        for(int d = num1.size();d>=0;d--) //в зависимости от длинны получившегося вектора начинаем циклом в обратном порядке вводить в строку цифры
        {
        ostringstream b;
        b << num1[d];
        s += b.str();
        }
        return s; //возвращаем строку
}

int decode(char a) //перевод символов в цифры
{
    switch (a)
    {
        case '0':
            return 0;
            break;
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 7;
            break;
        case '9':
            return 9;
            break;
        case 'A':
            return 10;
            break;
        case 'B':
            return 11;
            break;
        case 'C':
            return 12;
            break;
        case 'D':
            return 13;
            break;
        case 'E':
            return 14;
            break;
        case 'F':
            return 15;
            break;
        default:
            return -1;
            break;
    }
}

string func(int sys1,int sys2,string g)
{
    string result;
    int c,d,j,l = 0;
    int e = g.length(); //узнаём длинну строки
    char num[e];
    strcpy(num, g.c_str()); //переводим строку в символьный массив
    //присваеваем переменным значения систем
    c = sys1;
    d = sys2;
    if(sys1 == 10)//если начальная система исчисления 10, то просто присваем введённое число, переводя из строки в целочисленный тип
    {
        l = stoi(g);
    }
    if(sys1 != 10) //если начальная система исчисления не 10, то сначала декодируем символьный массив, затев переводим число в десятичную систему исчисления
    {
        for(int a = 0;a<e;a++)
        {
            j = decode(num[a]);
            l += j * pow(sys1,e-(a+1));
        }
        sys1 = 10;
    }
    if(sys2 != 10) //к этому моменту начальная система исчисления в любом случае равна десяти, если конечная система исчисления не равна десяти, то мы вызываем функцию перевода
    {
        g = func1(l,sys2); //присваеваем значение из функции строке g, которую потом будем возвращать
    }
    else //ну а если конечная равна десяти, то просто потоком переписываем число в строку, и возвращаем её
    {
    stringstream b;
    b << l;
    b >> g;
    }

    return g;
}

int main()
{
    setlocale(LC_ALL, "Russian"); //локализируем консоль
    //вводим переменные
    string number;
    int start_system,result_system;
    //взаимодействие с пользователем
    cout << "Введите число" <<endl;
    cin >> number;
    cout << "Введите начальную систему исчисления" << endl;
    cin >> start_system;
    cout << "Введите конечную систему исчисления" << endl;
    cin >> result_system;
    //проверка на системы исчисления
    if(((start_system && result_system) < 2) && (start_system && result_system > 16))
    cout << "Система исчеесления может быть только в интервале от двух до шестнадцати" << endl;
    else
    {
        cout << func(start_system,result_system,number);
    }
    return 0;
}
