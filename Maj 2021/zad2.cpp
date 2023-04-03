#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
	std::ifstream source("instrukcje.txt");
	std::ofstream result("wyniki4.txt", std::fstream::app);
	std::vector<std::string> instruction;

	int count = 1;
	int temp = 0;
	std::string tempName = "";

	for (std::string line; std::getline(source, line);)
	{
		instruction.push_back(line);
	}
	for (int i = 1; i < instruction.size(); i++)
	{
		if (instruction[i][0] == instruction[i - 1][0]) {
			count++;
		}
		else {
			count = 1;
		}
		if (count > temp)
		{
			temp = count;
			instruction[i].pop_back();
			instruction[i].pop_back();
			tempName = instruction[i];
		}

	}
	std::cout << tempName << " " << temp;

	result << "zadanie 4.2\n" << tempName << " " << temp << "\n";

	source.close();
	result.close();

	return 0;
}