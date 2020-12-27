//Обработка текстовых файлов - Поиск определенного слова в текстовом файле.
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
//вводим переменные
    int k = 0;
    string checker,word,text; 
    setlocale(LC_ALL, "Russian"); //локализируем консоль
    ofstream outfile("D://obrabotka.txt"); //создаём файл на диске
    ofstream file;
    file.open("D://obrabotka.txt"); //открываем его
    cout << "Введите требуемый текст" << endl; //просим у пользователя ввести текст
    cin >> text;
    file << text; //записываем его в файл
    file.close(); //закрываем файл
    ifstream infile("D://obrabotka.txt"); //открываем файл
    cout << "Введите слово для поиска" << endl; //просим ввести слово для поиска
    cin >> word; 
    while(infile >> checker) //циклом записываем текст из файла в строку
    {
        if(checker == word) //если нам попадается слово - сообщаем об это пользователю, обновляем счётчик и выходим из цикла
            {
            cout << "Слово - " << word << " найдено в файле." <<  endl;
            k = 5;
            break;
            }
        else //если слово не попадается отнимаем от счётчика еденицу
            k--;
    }
    if(k != 5) //если счётчик за весь цикл не принял значение 5, значит слово найдено не было, о чём и сообщаем пользователю
        cout << "Слово - " << word << " не было найдено в файле" << endl;
    return 0;
}
