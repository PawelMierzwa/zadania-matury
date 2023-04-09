#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::ifstream source("liczby.txt");
	std::ofstream result("wyniki4.txt", std::fstream::app);

	std::string line;

	std::string tempMax;
	std::string tempMin;

	int posMax = 0;
	int posMin = 0;

	std::vector<std::string> vector;

	while (source >> line) {
		vector.push_back(line);
	}

	tempMax = vector[0];
	tempMin = vector[0];

	for (size_t i = 0; i < vector.size(); i++) {
		std::string current = vector[i];
		
		if (current.size() >= tempMax.size())
		{
			if (current > tempMax)
			{
				tempMax = current;
				posMax = i+1;
			}
		}
		if (current.size() <= tempMin.size())
		{
			if (current < tempMin)
			{
				tempMin = current;
				posMin = i+1;
			}
		}
	}

	result << "Najwieksza: " << posMax << "\nNajmniejsza: " << posMin << "\n";

	source.close();
	result.close();

	return 0;
}