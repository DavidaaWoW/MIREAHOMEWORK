//8 задача - "Умножение матриц"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); //локализируем консоль
    int biggestcounter,smallestcounter,comisscounter1,comisscounter2; //вводим счётчики
    float biggest = 0,smallest = 999,comiss1 = 0,comiss2 = 999,summcash,summcomiss,summcashall; //вводим необходимые переменные
    //вводим матрицы
    float a[3][4] = {{5,2,0,10},
                    {3,5,2,5},
                    {20,0,0,0}};
    float b[4][2] = {{1.2,0.5},
                    {2.8,0.4},
                    {5,1},
                    {2,1.5}};
    float c[3][2]; //матрица, получающияся при умножении
    float x11,x12,x21,x22,x31,x32,x41,x42; //элементы матрицы
    for(int d = 0;d<4;d++) //умножаем матрицы по формуле
    {
        x11 += a[0][d] * b[d][0];
        x12 += a[0][d] * b[d][1];
        x21 += a[1][d] * b[d][0];
        x22 += a[1][d] * b[d][1];
        x31 += a[2][d] * b[d][0];
        x32 += a[2][d] * b[d][1];
        x41 += a[3][d] * b[d][0];
        x42 += a[3][d] * b[d][1];
    }
    //вносим элементы в матрицу
    c[0][0] = x11;
    c[0][1] = x12;
    c[1][0] = x21;
    c[1][1] = x22;
    c[2][0] = x31;
    c[2][1] = x32;
    c[3][0] = x41;
    c[3][0] = x42;
    for(int a = 0;a<3;a++) //функция по сути просеивает нужные значения, сначала присваивает все значения первым элементам матриц, если при переборе находится элемент "получше", то старый заменяется им
    {
        float diff[3];
        diff[a] = c[a][0] - c[a][1]; //находим разность
        if(diff[a] > biggest)
        {
            biggest = diff[a]; //количество денег, максимально заработанных продавцом
            biggestcounter = a + 1; //находим номер продавца
        }
        if(diff[a] < smallest)
        {
            smallest = diff[a]; //минимально заработанное кол-во денег
            smallestcounter = a + 1; //номер продавца
        }
        if(c[a][1] > comiss1)
        {
            comiss1 = c[a][1]; //наибольшая комиссия
            comisscounter1 = a + 1; //номер продавца
        }
        if(c[a][1] < comiss2)
        {
            comiss2 = c[a][1]; //наименьшая комиссия
            comisscounter2 = a + 1; //номер продавца
        }
        //находим оставшиеся значения
        summcash += diff[a]; 
        summcomiss += c[a][1];
        summcashall += c[a][0];
    }
    //после "просеивания" выводим нужный результат
    cout << "Больше всего заработал продавец №" << biggestcounter << " - " << biggest << endl;
    cout << "Меньше всего заработал продавец №" << smallestcounter << " - " << smallest << endl;
    cout << "Наибольшую комиссию заплатил продавец №" << comisscounter1 << " - " << comiss1 << endl;
    cout << "Наименьшую комиссию заплатил продавец №" << comisscounter2 << " - " << comiss2 << endl;
    cout << "Общая сумма денег, вырученная за проданные товары равна - " << summcash << endl;
    cout << "Общая комиссия заплаченная продавцами - " << summcomiss << endl;
    cout << "Общая сумма денег, прошедшая через руки продавцов - " << summcashall << endl;
    return 0;
}
