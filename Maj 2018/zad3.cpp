#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

bool isGapSmallerOrEqual10(char letter1, char letter2) {
    int pos1 = letter1 - 'A';
    int pos2 = letter2 - 'A';
    return std::abs(pos1 - pos2) <= 10;
}

int main()
{
    std::ifstream source("sygnaly.txt");
    std::ofstream result("wyniki4.txt", std::fstream::app);

    result << "zadanie 4.3\n";

    std::string word;

    while (source >> word)
    {
        bool meetsCriteria = true;
        for (size_t i = 0; i < word.size()-1; i++)
        {
            for (size_t j = i + 1; j < word.size(); j++)
            {
                meetsCriteria = meetsCriteria && isGapSmallerOrEqual10(word[i], word[j]);
            }
        }
        if (meetsCriteria)
        {
            result << word << "\n";
        }
    }

    source.close();
    result.close();

    return 0;
}