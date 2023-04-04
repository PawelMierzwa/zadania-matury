#include <iostream>
#include <fstream>
#include <string>

int getNumber(std::string line) {
	size_t pos = line.find(' ');
	if (pos == 2)
	{
		return std::stoi(line.substr(0, 2));
	}
	if (pos == 1)
	{
		return line.front() - '0';
	}
}

std::string getWord(std::string line) {
	size_t pos = line.find_first_of(' ');
	return line.substr(pos+1);
}

int main() {

	std::ifstream source("pary.txt");
	std::ofstream result("wyniki4.txt", std::fstream::app);

	std::string tempLine = "99 zzzzzzzzzzz"; // something awfuly big so anything gets overwriten in the first iteration

	for (std::string line; getline(source, line);) {
		std::string word = getWord(line);
		int number = getNumber(line);
		if (number == word.size())
		{
			std::cout << "number: " << number << "| word: " << word << "\n"; // debug log
			if (number < getNumber(tempLine) || (number == getNumber(tempLine) && word < getWord(tempLine)))
			{
				std::cout << "line found: " << tempLine << "\n"; //debug log
				tempLine = line;
			}
		}
	}

	result << "zadanie 4.3\n" << tempLine << "\n";

	source.close();
	result.close();

	return 0;
}