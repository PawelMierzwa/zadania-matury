#include <iostream>
#include <fstream>
#include <vector>

void getTableOfDigits(int number, std::vector<int>& digits) {

	while (number != 0)
	{
		digits.push_back(number % 10);
		number /= 10;
	}
}

bool isMeetingCriteria(int number) {

	std::vector<int> digits;
	getTableOfDigits(number, digits);
	if (digits.front() == digits.back()) {
		digits.clear();
		return true;
	}
	digits.clear();
	return false;
}

int main1() {

	std::ifstream source("liczby.txt");
	std::ofstream result;
	result.open("wynik4.txt", std::fstream::app);
	int number;

	int count = 0;
	bool found = false;

	while (source >> number) {
		if (isMeetingCriteria(number))
		{
			if (!found) {
				result << number << " ";
				found = true;
			}
			count++;
		}
	}
	result << count << "\n";
	source.close();
	result.close();
	return 0;
}
