#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    string inputFilename, wordToSearch;

    cout << "Введите имя файла: ";
    cin >> inputFilename;
    cout << "Введите слово для поиска: ";
    cin >> wordToSearch;

    ifstream inputFile(inputFilename);

    if (!inputFile.is_open())
    {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    int wordCount = 0;
    string line, word;

    while (getline(inputFile, line))
    {
        stringstream ss(line); // Используем stringstream для разделения строки на слова
        while (ss >> word)
        {
            if (word == wordToSearch)
            {
                wordCount++;
            }
        }
    }

    cout << "Слово '" << wordToSearch << "' встречается в файле "
        << wordCount << " раз(а)." << endl;

    inputFile.close();

    return 0;
}
