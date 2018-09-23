#include <iostream>
#include <fstream>
#include <vector>
#include <map>

bool is_separator(char symbol) {
	return (!(std::isdigit(symbol) || std::isalpha(symbol)));
}

std::vector<std::string> Parse_into_words(std::string line) {
	int32_t number_of_symbols = line.length();
	char symbol = 0;
	std::string word = "";
	std::vector<std::string> words = std::vector<std::string>();
	bool amount_of_words = 0;
	for (int32_t i = 0; i < number_of_symbols; ++i) {
		symbol = line[i];
		if (!is_separator(symbol)) {
			word = word + symbol;
			if (i == number_of_symbols - 1) {
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

void Print_map (std::map<std::string, int32_t> my_map) {
	for (std::map<std::string,int32_t>::iterator it = my_map.begin(); it!=my_map.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}


std::vector<std::string> Get_lines (std::string input) { 
	std::ifstream input_file (input);
	std::vector<std::string> lines;
    std::string line;
    while (std::getline(input_file, line)) {
        lines.push_back(line);
    }
    return lines;		
}


std::map<std::string, int32_t> Words_classification (std::map<std::string, int32_t> frequency, std::vector<std::string> words) {
	std::map<std::string,int32_t>:: iterator it = frequency.find(words[0]);
	for (int32_t i = 0; i < words.size(); ++i) {
		it = frequency.find(words[i]);
		if (it != frequency.end()) {
			it->second +=1; 
		}
		else {
			frequency[words[i]] = 1;
		}
	}
	return frequency;
}


int32_t Words_counter (std::map<std::string, int32_t> my_map) {
	int32_t number_of_words = 0;
	for (std::map<std::string, int32_t>::iterator it=my_map.begin(); it!=my_map.end(); ++it) {
    	number_of_words += it->second;
	}
    return number_of_words;
}


std::vector<double> Frequency_percentage (std::map <std::string, int32_t> my_map) { 
	int32_t number_of_words = Words_counter(my_map);
	std::vector<double> percentage;
	int32_t i = 0;
	for (std::map<std::string,int32_t>::iterator it=my_map.begin(); it!=my_map.end(); ++it) {
    	percentage[i] = it->second * 100 / number_of_words;
    	++i;
	}
	return percentage;
}


void Words_finder (std::string input) {
	std::vector<std::string> lines = Get_lines(input); 
	std::vector<std::string> words;
	std::map<std::string, int32_t> frequency;
	
	for (int32_t i = 0; i < lines.size(); ++i) {
		words = Parse_into_words (lines[i]);
		frequency = Words_classification (frequency, words);
	}

	Print_map (frequency);
 	/* сортируем frequency, Frequency_percentage (sorted_frequency), запись в файл */

}


int main()
{
	setlocale(LC_ALL, "Russian");
	std::string input = "";
	std::string output = "";
	std::cin >> input >> output ;
	std::ofstream output_file (output);
	output_file << "wewefw";
   	Words_finder(input);

	return 0;
}