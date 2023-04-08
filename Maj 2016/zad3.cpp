#include <iostream>
#include <fstream>
#include <string>

std::string getWord(const std::string line) {
	size_t pos = line.find_first_of(' ');
	std::string word = line.substr(0, pos);
	return word;
}

std::string getCipher(const std::string line) {
	size_t pos = line.find_first_of(' ');
	std::string cypher = line.substr(pos + 1);
	return cypher;
}

std::string cipher(const std::string word, int key) {
	std::string result = "";
	for (int i = 0; i < word.length(); i++) {
		char c = word[i];
		c = ((c - 'A') + key) % 26 + 'A';
		result += c;
	}
	return result;
}

int main()
{
	std::ifstream source("dane_6_3.txt");
	std::ofstream result("wyniki_6_3.txt");

	std::string str;

	while (std::getline(source, str)) {

		if (str.empty()) continue;

		std::string word = getWord(str);
		std::string ciphered = getCipher(str);

		if (word.empty() || ciphered.empty()) continue;

		int key = std::abs((ciphered[0] - word[0] + 26) % 26);

		if (ciphered != cipher(word, key))
		{
			std::cout << ciphered << " | " << cipher(ciphered, key) << "\n";
			result << word << "\n";
		}
	}

	source.close();
	result.close();

	return 0;
}