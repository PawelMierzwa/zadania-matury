#include <iostream>
#include <fstream>
#include <string>

char get10thLetter(std::string Str) {
    return Str[9];
}

int main()
{
    std::ifstream source("sygnaly.txt");
    std::ofstream result("wyniki4.txt", std::fstream::app);

    result << "zadanie 4.1\n";

    std::string word;

    int count = 0;
    std::string message = "";

    while (source >> word)
    {
        count++;
        if (count == 40)
        {
            message += get10thLetter(word);
            count = 0;
        }
    }

    result << message << "\n";

    source.close();
    result.close();

    return 0;
}