#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//this code should take the instruction from the file and change the output string accordingly.

char getLastLetter(std::string& String) {
	return String.back();
}

int getInstruction(std::string String) {
	if (String.empty())
	{
		return 0;
	}
	String.pop_back();
	String.pop_back();

	int instruction = 0;

	if (String == "DOPISZ") // add letter provided after the instruction ex. "DOPISZ G"
	{
		instruction = 1;
	}
	else if (String == "USUN") // delete the last letter
	{
		instruction = 2;
	}
	else if (String == "ZMIEN") // change last letter to provided one
	{
		instruction = 3;
	}
	else // change first found letter to a next one in the alphabet
	{
		instruction = 4;
	}

	return instruction;
}

int main()
{
	std::ifstream source("instrukcje.txt");
	std::ofstream result("wyniki4.txt", std::fstream::app);
	std::string wynik = "";

	for (std::string line; std::getline(source, line);)
	{
		if (line.empty())
		{
			continue;
		}
		std::cout << line << "\n";
		int inst = getInstruction(line);
		char letter;
		if (inst != 2)
		{
			letter = getLastLetter(line);
		}
		switch (inst)
		{
		case 1:
			wynik += letter; //dodaj
			break;
		case 2:
			if (!wynik.empty())
			{
				wynik.pop_back(); //usun
			}
			break;
		case 3:
			wynik.back() = letter; //zmien
			break;
		case 4:
			size_t pos = wynik.find_first_of(letter);
			if (wynik[pos] == 'Z') {
				wynik[pos] = 'A';
			}
			else if (pos != std::string::npos)
			{
				wynik[pos] = static_cast<char>(letter + 1); //zmien na litere o jedna do przodu
			}
			break;
		}
		std::cout << wynik << "\n";
	}

	result << "zadanie 4.4\n" << wynik;

	source.close();
	result.close();

	return 0;
}