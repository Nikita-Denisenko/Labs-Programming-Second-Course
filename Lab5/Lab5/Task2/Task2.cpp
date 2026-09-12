#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

bool IsSeparator(char ch)
{
    return ch == ' ' ||
        ch == '.' ||
        ch == ',' ||
        ch == '-' ||
        ch == ':' ||
        ch == '!' ||
        ch == ';' ||
        ch == '\n' ||
        ch == '\r';
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string fileName;

    std::cout << "Введите имя текстового файла: ";
    std::cin >> fileName;

    std::ifstream file(fileName);

    if (!file)
    {
        std::cout << "Не удалось открыть файл.\n";
        return 1;
    }

    std::map<std::string, int> wordCount;

    std::string word;
    char ch;

    while (file.get(ch))
    {
        if (IsSeparator(ch))
        {
            if (word.length() > 3)
            {
                ++wordCount[word];
            }

            word.clear();
        }
        else
        {
            word += ch;
        }
    }

    if (word.length() > 3)
    {
        ++wordCount[word];
    }

    file.close();

    std::vector<std::pair<std::string, int>> result;

    for (const auto& pair : wordCount)
    {
        if (pair.second >= 7)
        {
            result.push_back(pair);
        }
    }

    std::sort(
        result.begin(),
        result.end(),
        [](const auto& a, const auto& b)
        {
            return a.second > b.second;
        });

    std::cout << "\nСлова, встречающиеся не менее 7 раз:\n\n";

    if (result.empty())
    {
        std::cout << "Подходящих слов нет.\n";
    }
    else
    {
        for (const auto& pair : result)
        {
            std::cout << pair.first
                << " - "
                << pair.second
                << '\n';
        }
    }

    return 0;
}