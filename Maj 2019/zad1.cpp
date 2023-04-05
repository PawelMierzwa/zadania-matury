#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream source("liczby.txt");
	std::ofstream result("wyniki4.txt", std::fstream::app);

	result << "zadanie 4.1\n";

	int number, count = 1;

	std::vector<int> threes;

	int i = 1;

	while (i < 100000)
	{
		i *= 3;
		threes.push_back(i);
	}

	while (source >> number)
	{
		for (int j = 0; j < threes.size(); j++)
		{
			if (number == threes[j]) {
				count++;
			}
		}
	}
	result << count << "\n";

	source.close();
	result.close();

	return 0;
}