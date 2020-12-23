//2-ая задача - Ввести с клавиатуры два числа и найти их сумму, разность, произведение и, если возможно, частное от деления одного на другое
#include <iostream>

using namespace std;

int main()
{
int x,y; //объявляем переменные
cout << "Enter first number: " << endl;
cin >> x; //даём ввести первое число с клавиатуры
cout << "Enter second number: " << endl;
cin >> y; //и второе
//далее выводим сумму, разность и произведение
cout << "Sum of two numbers: " << x + y << endl;
cout << "Difference between two numbers: " << x - y << endl;
cout << "Multiplication of two numbers: " << x * y << endl;
if (y != 0) //если делитель не равен нулю, выводим частное
{
    cout << "Quotient of two numbers: " << x / y << endl;
}
else //в противном случае выводим сообщение об ошибке
{
    cout << "Cannot be divided by zero" << endl;
}
return 0;
}
