#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream source("liczby.txt");
    std::ofstream result("wyniki4.txt", std::fstream::app);

    std::string line;

    int count2 = 0;
    int count8 = 0;

    while (source >> line) {

        if (line.empty())
        {
            continue;
        }

        if (line.back() == '0')
        {
            count2++;
            line.pop_back();
            if (line.back() == '0')
            {
                line.pop_back();
                if (line.back() == '0') {
                    count8++;
                }
            }
        }
    }
    result << "ilosc liczb podzielnych:\nprzez 2: " << count2 << "\nprzez 8: " << count8 << "\n";

    source.close();
    result.close();

    return 0;
}