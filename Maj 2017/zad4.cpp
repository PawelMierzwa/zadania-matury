#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<int> getRow(std::string row) {
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

	result << "zadanie 6.4\n";

	std::vector<std::vector<int>> matrix;

	for (std::string row; getline(source, row);) {
		matrix.push_back(getRow(row));
	}

	int count = 1;

	for (size_t j = 0; j < matrix[0].size(); j++)
	{
		int tempCount = 1;
		for (size_t i = 0; i < matrix.size() - 1; i++)
		{
			if (matrix[i][j] == matrix[i+1][j])
			{
				tempCount++;
			}
			else {
				if (tempCount > count)
				{
					count = tempCount;
				}
				tempCount = 1;
			}
		}
		if (tempCount > count)
		{
			count = tempCount;
		}
	}

	result << count << "\n";

	source.close();
	result.close();

	return 0;
}