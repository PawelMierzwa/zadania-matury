#include <iostream>
#include <fstream>
#include <vector>
#include <set>

std::vector<int> getPrimeFactors(int number) {
	
	std::vector<int> primeFactors;
	int factor = 2;
	int temp = number;
	while (temp > 1)
	{
		if (temp % factor == 0)
		{
			primeFactors.push_back(factor);
			temp = temp / factor;
		}
		else {
			factor++;
		}
	}

	return primeFactors;
}

int main2() {

	std::vector<int> primeFactors;
	std::ifstream source("liczby.txt");
	std::ofstream result("wynik4.txt", std::fstream::app);

	int number;

	int tempSize1 = 0;
	int tempNumber1 = 0;

	int tempSize2 = 0;
	int tempNumber2 = 0;


	while (source >> number)
	{
		primeFactors = getPrimeFactors(number);
		if (primeFactors.size()>tempSize1)
		{
			tempSize1 = primeFactors.size();
			tempNumber1 = number;
		}

		std::set<int> differentPrimeFactors(primeFactors.begin(), primeFactors.end());
		if (differentPrimeFactors.size()>tempSize2)
		{
			tempSize2 = differentPrimeFactors.size();
			tempNumber2 = number;
		}

		primeFactors.clear();
		differentPrimeFactors.clear();
	}
	result << tempNumber1 << " " << tempSize1 << " " << tempNumber2 << " " << tempSize2 << "\n";

	source.close();
	result.close();

	return 0;
}
// kod psc za zdanie egzaminu 1231875825638176