//3 задача «Копирование файла». Создать на диске текстовый файл и скопировать его на экран.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    setlocale (LC_ALL, "Russian"); //локализируем консоль
    ofstream outfile("D://pp.txt"); //создаём файл на диске
    ofstream pp; //обозначаем его в программе
    pp.open("D://pp.txt"); //открываем файл
    pp << "My name is David"; //вводим в него требуемуй текст
    pp.close(); //закрываем файл
    ifstream infile("D://pp.txt"); //открываем файл с диска
    string aoao; //создаём переменную типа 'string'
    getline(infile, aoao); //вводим в переменную строку из файла
    cout << aoao << endl; //выводим на экран строку
    return 0;
}
