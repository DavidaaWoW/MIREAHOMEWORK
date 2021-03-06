/* Не про спиннеры. Саша совсем не любит спиннеры, поэтому он рисует в тетрадке. Он взял тетрадный
лист из N × M клеточек и пронумеровал все клетки различными числами. Теперь ему стало
интересно, сколько различных прямоугольников он может вырезать из этого листа бумаги по
границам клеточек.
Программа получает на вход два числа N и M – размеры исходного листа. Все числа –
целые положительные, не превосходящие 75000.
Программа должна вывести одно число – количество прямоугольников, которые
можно вырезать из данного листа бумаги (весь лист целиком также считается одним из
возможных прямоугольников).
*/
#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    uint64_t m,n; //вводим 64-битные числа, т.к получаются очень большие значения
    setlocale(LC_ALL, "Russian"); //локализируем консоль
    cout << "Введите размеры клеток" << endl; //просим у пользователя ввести размеры
    cin >> n >> m;
    cout << "Максимально возможное количество прямоугольников равно: " << n*(n+1)/2*m*(m+1)/2 << endl; //эту задача решается через два цикла, первый - n+(n-1)+...+1, и второй - m+(m+1)+...+1, сумма первого цикла равна n(n+1)/2, а второго соответственно m(m+1)/2, если перемножить два этих числа, то получим ответ на задачу.
    return 0;
}
