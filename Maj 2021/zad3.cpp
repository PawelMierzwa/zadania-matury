#include <iostream>
#include <fstream>
#include <string>

char nthLetter(int n) {
	if (n >= 0 && n <= 25)
	{
		return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n+1];

	}
	return ' ';
}

int main() {

	std::ifstream source("instrukcje.txt");
	std::ofstream result("wyniki4.txt", std::fstream::app);

	int tab[25] = {};
	int temp = 0;
	char letter = ' ';

	for (int i = 0; i < 24; i++)
	{
		tab[i] = 0;
	}

	for (std::string line; std::getline(source, line);)
	{
		if (line.front() == 'D')
		{
			int index = static_cast<char>(line.back()) - 'B';
			if (index >= 1 && index <= 25)
			{
				tab[index]++;
			}
		}
		
	}

	for (int i = 0; i < 25; i++)
	{
		if (tab[i] > temp)
		{
			temp = tab[i];
			letter = nthLetter(i);
		}
	}

	std::cout << letter << " " << temp;
	result << "zadanie 4.3\n" << letter << " " << temp << "\n";

	source.close();
	result.close();

	return 0;
}