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

	result << "zadanie 6.3\n";

	std::vector<std::vector<int>> matrix;

	for (std::string row; getline(source, row);) {
		matrix.push_back(getRow(row));
	}

	int count = 0;

	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[i].size(); j++)
		{
			if (i > 0 && std::abs(matrix[i][j] - matrix[i - 1][j]) > 128) {
				count++;
			}
			else if (j < matrix[i].size() - 1 && std::abs(matrix[i][j] - matrix[i][j + 1]) > 128) {
				count++;
			}
			else if (j > 0 && std::abs(matrix[i][j] - matrix[i][j - 1]) > 128) {
				count++;
			}
			else if (i < matrix.size() - 1 && std::abs(matrix[i][j] - matrix[i + 1][j]) > 128) {
				count++;
			}
		}
	}

	result << count << "\n";

	source.close();
	result.close();

	return 0;
}