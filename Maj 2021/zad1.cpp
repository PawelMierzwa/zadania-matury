#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream source("instrukcje.txt");
	std::ofstream result("wyniki4.txt", std::fstream::app);

	int countD = 0, countU = 0;

	for (std::string line; std::getline(source, line);)
	{
		char first = line[0];
		if (first == 'D')
		{
			countD++;
		}
		else if (first == 'U')
		{
			countU++;
		}
	}

	int count = countD - countU;

	result << "zadanie 4.1\n" << count << "\n";

	source.close();
	result.close();

	return 0;
}