#include <iostream>
#include <fstream>
#include <vector>
#include <map>

bool is_separator(char symbol) {
	return (!(std::isdigit(symbol) || std::isalpha(symbol)));
}

std::vector<std::string> parse_into_words(std::string line) {
	int number_of_symbols = line.length();
	char symbol = 0;
	std::string word = "";
	std::vector<std::string> words = std::vector<std::string>();
	bool amount_of_words = 0;
	for (int i = 0; i < number_of_symbols; i++) {
		symbol = line[i];
		if (!is_separator(symbol)) {
			word = word + symbol;
			if (i == number_of_symbols-1) {
				words.push_back(word);
			}
		}
		else {
			words.push_back(word);
			word = "";
		}
	}
	return words;
}

int main()
{
	std::string input = "";
	std::string output = "";
	std::cin >> input >> output ;
	std::ifstream input_file (input);
	std::ofstream output_file (output);
	output_file << "wewefw";

	std::vector<std::string> lines;
    std::string line;
    while (std::getline(input_file, line)) {
        lines.push_back(line);
    }

    int number_of_lines = lines.size();

    
	std::cout << is_separator('_');
	std::cout << is_separator('&');
	std::cout << is_separator('s');
	std::cout << is_separator('9');

	std::string ilya_lalka = "efsdsdf,gg8gr,34rg67rgrgr&h";
	std::vector<std::string> out_array = parse_into_words(ilya_lalka);
	int len = out_array.size();
	for (int i = 0; i < len; i++) {
		std::cout << out_array[i] << "\n";
	}
	



	return 0;
}