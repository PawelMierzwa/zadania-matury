#include <iostream>
#include <fstream>
#include <string>

std::string getWord(std::string line) {
	size_t pos = line.find_first_of(' ');
	std::string word = line.substr(0, pos);
	return word;
}

int getKey(std::string line) {
	size_t pos = line.find_first_of(' ');
	int key = 0;
	if (line[pos+1])
	{
		key = std::stoi(line.substr(pos + 1));
	}
	return key;
}

int main()
{
	std::ifstream source("dane_6_2.txt");
	std::ofstream result("wyniki_6_2.txt");

	std::string str;

	for (std::string line; getline(source, line);) {
		std::string word = getWord(line);
		int k = getKey(line);
		k = k % 26;
		std::string out;
		for (int i = 0; i < word.size(); i++)
		{
			if (word[i] - k < 65)
			{
				out += 'Z' - (k - (word[i] - 'A') - 1);
			}
			else
			{
				out += word[i] - k;
			}
		}
		result << out << "\n";
	}

	source.close();
	result.close();

	return 0;
}
