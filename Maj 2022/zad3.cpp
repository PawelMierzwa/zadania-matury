#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool isCorrectStringOf3(int a, int b, int c) {
	return (a != b && b != c && b % a == 0 && c % b == 0);
}

bool isCorrectStringOf5(int a, int b, int c, int d, int e) {
	if (a == b || b == c || c == d || d == e) {
		return false;
	}
	if (b % a != 0 || c % b != 0 || d % c != 0 || e % d != 0) {
		return false;
	}
	return true;
}

int main() {
	std::ifstream source("liczby.txt");
	std::ofstream result3("trojki.txt", std::fstream::app);
	std::ofstream result5("piatki.txt", std::fstream::app);

	std::vector<int> numbers;
	int number;
	while (source >> number)
	{
		numbers.push_back(number);
	}

	std::sort(numbers.begin(), numbers.end());

	int count3 = 0;
	int count5 = 0;

	for (int i = 0; i < numbers.size(); i++)
		for (int j = i + 1; j < numbers.size(); j++)
			for (int k = j + 1; k < numbers.size(); k++)
			{
				int r = isCorrectStringOf3(numbers[i], numbers[j], numbers[k]);
				count3 += r;
				if (r == 1)
					result3 << numbers[i] << " " << numbers[j] << " " << numbers[k] << "\n";
			}

	for (int i = 0; i < numbers.size(); i++)
		for (int j = i + 1; j < numbers.size(); j++)
			for (int k = j + 1; k < numbers.size(); k++)
				for (int l = k + 1; l < numbers.size(); l++)
					for (int m = l + 1; m < numbers.size(); m++)
					{
						int r = isCorrectStringOf5(numbers[i], numbers[j], numbers[k], numbers[l], numbers[m]);
						count5 += r;
						if (r == 1)
							result5 << numbers[i] << " " << numbers[j] << " " << numbers[k] << " " << numbers[l] << " " << numbers[m] << "\n";
					}

	source.close();
	result3.close();
	result5.close();
	return 0;
}