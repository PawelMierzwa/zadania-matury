#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<int> getRowVector(std::string row) {
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
	return rowVector;
}

int main()
{
	std::ifstream source("dane.txt");
	std::ofstream result("wyniki6.txt", std::fstream::app);

	result << "zadanie 6.1\n";

	int tempMax = 0;
	int tempMin = 255;

	for (std::string line; getline(source, line);) {
		if (line.empty())
		{
			continue;
		}
		std::vector<int> row = getRowVector(line);
		for (size_t i = 0; i < row.size(); i++)
		{
			if (row[i] > tempMax)
			{
				tempMax = row[i];
			}
			else if (row[i] < tempMin)
			{
				tempMin = row[i];
			}
		}
	}

	result << tempMax << " " << tempMin << "\n";

	source.close();
	result.close();

	return 0;
}