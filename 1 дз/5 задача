//5 задача - В комнате светло, если на улице день и раздвинуты шторы или если включена лампа. Программа должна, в зависимости от времени суток и состояния лампы и штор, отвечать на вопрос, светло ли в комнате.
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
//вводим булевые переменные
bool day;
bool curtains_on;
bool lamp_on;
cout << "Если утверждение верно, надо набрать на клавиатуре 1, если ложно то 0" << endl;
//далее спрашиваем у пользователя характеристики переменных
cout << "Лампа включена? " << endl;
cin >> lamp_on;
cout << "На улице день? " << endl;
cin >> day;
cout << "Шторы открыты? " << endl;
cin >> curtains_on;
//для упрощения задачи объединяем все необходимые условия под один if
if (lamp_on == true || (day == true && curtains_on == true))
{
    cout << "В комнате светло! :)" << endl;
}
else
{
    cout << "В комнате темно! :(" << endl;
}
    return 0;
}
