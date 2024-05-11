#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    string inputFilename, outputFilename;

    cout << "Введите имя исходного файла: ";
    cin >> inputFilename;
    cout << "Введите имя файла для результата: ";
    cin >> outputFilename;

    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cerr << "Ошибка открытия файлов!" << endl;
        return 1;
    }

    string line, previousLine;
    while (getline(inputFile, line))
    {
        if (!inputFile.eof())
        {
            outputFile << previousLine << endl;
        }
        previousLine = line;
    }

    cout << "Последняя строка удалена. Результат записан в файл " << outputFilename << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
