/*Файлы - Создать файл из N вещественных чисел в десятичной системе счисления. В другой файл записать эти числа, переведенные из
исходного файла в любую систему счисления по желанию
пользователя в пределах от 2-ой до 9-ой.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int func1(int r,int y)
{
    return r*10+y;
}

int func(int s) //функция перевода чисел, более подробное описание, есть в 9 задаче 4 д/з
{
    int f = 0,v;
    vector <int> arr;
    while((s!=0)&&(s!=1))
    {
        f = s%2;
        arr.insert(arr.begin(),f);
        s /= 2;
    }
    arr.insert(arr.begin(),s);
    v = accumulate(arr.begin(),arr.end(),0,func1);
    return v;
}

int main()
{
    //вводим переменные
    string l;
    int n;
    int p = 0;
    setlocale(LC_ALL, "Russian"); //локализируем консоль
    int m[10] = {23,34,54,83,19,12,94,47,29,50}; //создаём массив с числами в десятичной системе счисления
    int k[10];
    ofstream outfile("D://file.txt"); //создаём файл на диске
    ofstream file; 
    file.open("D://file.txt"); //открываем его
    for(int a = 0;a<10;a++) //вводим в файл числа, через пробел
    {
        file << m[a] << " ";
    }
    file.close(); //закрываем файл
    ifstream infile("D://file.txt"); //открываем файл
    while(infile >> l) //записываем из файла в строку числа
    {
        n = atoi(l.c_str()); //переводим из строки в числа
        k[p] = n; //записываем числа в массив
        p++; //переключаем счётчик
    }
    p = 0; //обнуляем счётчик
    infile.close(); //закрываем файл
    ofstream outfile1("D://result.txt"); //создаём файл, в котором будет хранится результат
    ofstream result;
    result.open("D://result.txt"); //открываем его
    while(p<10)
    {
        result << func(k[p]) << " "; //записываем числа полученные в функции через пробел в файл
        p++; //переключаем счётчик
    }
    result.close(); //закрываем файл
    return 0;
}

