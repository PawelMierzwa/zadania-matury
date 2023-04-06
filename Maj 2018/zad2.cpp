#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

int main()
{
    std::ifstream source("wyniki4.txt");
    std::ofstream result("wyniki4.txt", std::fstream::app);

    result << "zadanie 4.2\n";

    std::string word;

    int maxLength = 0;
    std::string maxWord = "";

    while (source >> word)
    {
        std::set<char> charSet(word.begin(), word.end());

        if (charSet.size() > maxLength)
        {
            maxLength = charSet.size();
            maxWord = word;
        }
    }

    result << maxWord << " " << maxLength << "\n";

    source.close();
    result.close();

    return 0;
}