#include <iostream>
#include <fstream>
#include <string>

std::string getWord(std::string line) {
	size_t pos = line.find_first_of(' ');
	return line.substr(pos);
}


int main() {

	std::ifstream source("pary.txt");
	std::ofstream result("wyniki4.txt", std::fstream::app);

	int count, temp;
	std::string tempName;

	result << "zadanie 4.2\n";

	for (std::string line; getline(source, line);) {

		if (line.empty())
		{
			continue;
		}
		count = 1;
		temp = 1;
		tempName = "";
		std::string str = getWord(line);

		for (int i = 1; i < str.size(); i++)
		{
			if (str[i] == str[i - 1])
			{
				count++;
				if (count > temp)
				{
					temp = count;
					tempName = "";
					for (int j = 0; j < count; j++)
					{
						tempName += str[i];
					}
				}
			}
			else {
				count = 1;
			}
		}
		if (temp == 1)
		{
			tempName = str[1];
		}
		result << tempName << " " << temp << "\n";
	}

	source.close();
	result.close();

	return 0;
}