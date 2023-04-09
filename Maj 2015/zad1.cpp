#include <iostream>
#include <fstream>
#include <string>

bool hasMoreZeros(std::string binaryNum) {
    int count0 = 0;
    int count1 = 0;
    for (size_t i = 0; i < binaryNum.size(); i++)
    {
        if (binaryNum[i] == '0') count0++;
        if (binaryNum[i] == '1') count1++;
    }
    return count0 > count1;
}

int main()
{
    std::ifstream source("liczby.txt");
    std::ofstream result("wyniki4.txt");

    std::string line;
    int count = 0;
    while (source >> line) {
        if (hasMoreZeros(line))
        {
            count++;
        }
    }
    result << count << "\n";

    source.close();
    result.close();

    return 0;
}