#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> getDigitVector(int number) {
	std::vector<int> resultVector;
	while (number != 0)
	{
		resultVector.push_back(number % 10);
		number /= 10;
	}

	return resultVector;
}

int getFactorial(int number) {
	int result = 1;
	for (int i = 0; i < number; i++)
	{
		result *= i + 1;
	}

	return result;
}

int main()
{
	std::ifstream source("liczby.txt");
	std::ofstream result("wyniki4.txt", std::fstream::app);

	result << "zadanie 4.2\n";

	int number;

	std::vector<int> digitVector;
	
	int sum = 0;

	while (source >> number)
	{
		digitVector = getDigitVector(number);
		for (size_t i = 0; i < digitVector.size(); i++)
		{
			sum += getFactorial(digitVector[i]);
		}
		std::cout << "number: " << number << "| sum: " << sum << std::endl;
		if (sum == number)
		{
			result << number << "\n";
		}
		digitVector.clear();
		sum = 0;
	}

	source.close();
	result.close();

	return 0;
}