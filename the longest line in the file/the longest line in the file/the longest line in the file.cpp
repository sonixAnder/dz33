#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    string inputFilename;
    cout << "Введите имя файла: ";
    cin >> inputFilename;

    ifstream inputFile(inputFilename);

    if (!inputFile.is_open())
    {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    int maxLength = 0;
    string line;

    while (getline(inputFile, line))
    {
        if (line.length() > maxLength)
        {
            maxLength = line.length();
        }
    }

    cout << "Длина самой длинной строки: " << maxLength << endl;

    inputFile.close();

    return 0;
}
