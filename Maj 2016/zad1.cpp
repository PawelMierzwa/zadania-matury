#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream source("dane_6_1.txt");
	std::ofstream result("wyniki_6_1.txt");

	std::string word;

	int k = 107 - 104; //usuwamy 104, bo 25 + 1 (ilosc wszystkich mozliwych znakow) * 4

	while (source >> word)
	{
		std::string out = "";
		for (int i = 0; i < word.size(); i++)
		{
			if (word[i] < 65 + 23)
			{
				out += word[i] + 3;
			}
			else
			{
				switch (word[i])
				{
				case 65 + 23:
					out += "A";
					break;
				case 65 + 24:
					out += "B";
					break;
				case 65 + 25:
					out += "C";
					break;
				default:
					break;
				}
			}
		}
		result << out << "\n";
	}
	source.close();
	result.close();

	return 0;
}
