#include <iostream>
#include <fstream>
#include <string>

int getNumber(std::string Str) {
	size_t pos = Str.find(' ');
	if (pos == 2)
	{
		return std::stoi(Str.substr(0, 2));
	}
	else if (pos == 1) return Str.front() - '0';
}

bool isPrimeNumber(int number) {
	if (number == 0 || number == 1)
	{
		return false;
	}

	for (int i = 2; i < number / 2 + 1; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	std::ifstream source("pary.txt");
	std::ofstream result("wyniki4.txt", std::fstream::app);

	int prime1, prime2;
	int temp;

	result << "zadanie 4.1\n";

	for (std::string line; getline(source, line);)
	{
		if (line.empty())
		{
			continue;
		}
		int num = getNumber(line);
		if (num % 2 == 0)
		{
			std::cout << num << "\n";
			prime1 = 0;
			prime2 = 0;
			temp = num - 1;
			while (temp > 0)
			{
				if (isPrimeNumber(temp) && isPrimeNumber(num - temp))
				{
					prime1 = temp;
					prime2 = num - temp;
					result << num << " " << prime2 << " " << prime1 << "\n";
					break;
				}
				temp--;
			}
		}
	}

	source.close();
	result.close();

	return 0;
}