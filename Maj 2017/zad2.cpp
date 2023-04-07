#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool isRowSymetrical(std::string row) {
	std::vector<int> rowVector;
	std::string number;
	for (size_t i = 0; i < row.size(); i++)
	{
		if (row[i] != ' ')
		{
			number.push_back(row[i]);
		}
		else
		{
			rowVector.push_back(std::stoi(number));
			number = "";
		}
	}
	if (!number.empty())
	{
		rowVector.push_back(std::stoi(number));
	}
	
	bool meetsCriteria = true;

	for (size_t j = 0; j < rowVector.size()-1; j++)
	{
		meetsCriteria = meetsCriteria && rowVector[j] == rowVector[rowVector.size() - 1 - j];
	}
	return meetsCriteria;
}

int main()
{
	std::ifstream source("dane.txt");
	std::ofstream result("wyniki6.txt", std::fstream::app);

	result << "zadanie 6.2\n";

	int count = 0;

	for (std::string line; getline(source, line);)
	{
		if (isRowSymetrical(line))
		{
			count++;
		}
	}

	result << 200 - count << "\n";

	source.close();
	result.close();

	return 0;
}