#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    string inputFilename, outputFilename, searchWord, replaceWord;

    cout << "Введите имя исходного файла: ";
    cin >> inputFilename;
    cout << "Введите имя файла для результата: ";
    cin >> outputFilename;
    cout << "Введите слово для поиска: ";
    cin >> searchWord;
    cout << "Введите слово для замены: ";
    cin >> replaceWord;

    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cerr << "Ошибка открытия файлов!" << endl;
        return 1;
    }

    string line;
    size_t pos;

    while (getline(inputFile, line))
    {
        while ((pos = line.find(searchWord)) != string::npos)
        {
            line.replace(pos, searchWord.length(), replaceWord);
        }
        outputFile << line << endl;
    }

    cout << "Слова заменены. Результат записан в файл " << outputFilename << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
