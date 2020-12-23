//5 задача
#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

void space1() //функция на 8 пробелов
{
    for(int a=0;a<8;a++)
    {
        cout << " ";
    }
}
void space2() //функция на 6 пробелов
{
    for(int a=0;a<6;a++)
    {
        cout << " ";
    }
}
void space3() //функция на 3 пробела
{
        for(int a=0;a<3;a++)
    {
        cout << " ";
    }
}
void space4() //функция на 4 пробела
{
    for(int a=0;a<4;a++)
    {
        cout << " ";
    }
}
void space5() //функция на 5 пробелов
{
        for(int a=0;a<5;a++)
    {
        cout << " ";
    }
}
void space6() //функция на 7 пробелов
{
        for(int a=0;a<7;a++)
    {
        cout << " ";
    }
}
void space7() //функция на 9 пробелов
{    for(int a=0;a<9;a++)
    {
        cout << " ";
    }
}
int main()
{
//выводим звёзды в перемешку с функциями пробелов
    for(int b = 0; b < 8; b++)
    {
        cout << '*';
        space7();
    }
    cout << endl;
    cout << " ";
    for(int c = 0; c<8;c++)
    {
        cout << '*';
        space6();
        cout << '*';
        cout << " ";
    }
    cout << endl;
    cout << "  ";
    for(int d = 0; d < 8; d++)
    {
        cout << '*';
        space5();
        cout << '*';
        space3();
    }
    cout << endl;
    space3();
    for(int e = 0; e < 8; e++)
    {
        cout << '*';
        space3();
        cout << '*';
        space5();
    }
    cout << endl;
    space4();
    for(int f = 0; f < 8; f++)
    {
        cout << '*' << " " << '*';
        space6();
    }
    cout << endl;
    space5();
    for(int g = 0;g < 8; g++)
    {
        cout << '*';
        space7();
    }
    return 0;
}
