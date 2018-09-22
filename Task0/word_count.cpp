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


std::vector<std::string> Get_lines (std::ifstream input_file) { 
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


int32_t Words_counter (std::map<std::string> my_map) {
	int32_t number_of_words = 0;
	for (std::map<char,int>::iterator it=my_map.begin(); it!=my_map.end(); ++it) {
    	number_of_words += it->second;
	}
    return number_of_words;
}


std::vector<double> Frequency_percentage (const std::map <std::string> &my_map) { 
	int32_t number_of_words = Words_counter(my_map);
	std::vector<double> percentage;
	int32_t i = 0;
	for (std::map<char,int>::iterator it=my_map.begin(); it!=my_map.end(); ++it) {
    	percentage[i] = it->second * 100 / number_of_words;
    	++i;
	}
	return percentage;
}


void Words_finder (std::ifstream input_file, std::ofstream output_file) {
	std::vector<std::string> lines = Get_lines(input_file); 
	std::vector<std::string> words;
	std::map<std::string, int32_t> frequency;
	
	for (int32_t i = 0; i < lines.size(); ++i) {
		words = Parse_into_words (lines[i]);
		frequency = Words_classification (frequency, words);
	}

 	/* сортируем frequency, Frequency_percentage (sorted_frequency), запись в файл */

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

    
	/*std::cout << is_separator('_');
	std::cout << is_separator('&');
	std::cout << is_separator('s');
	std::cout << is_separator('9');

	std::string ilya_lalka = "efsdsdf,gg8gr,34rg67rgrgr&h";
	std::vector<std::string> out_array = Parse_into_words("Shla Sasha__ s1 sushkoi");
	int len = out_array.size();
	for (int i = 0; i < len; i++) {
		std::cout << out_array[i] << "\n";
	}
	*/
	std::vector<std::string> words = Parse_into_words("Shla Sasha po shosse po po shosse");
   	Words_finder(words);

	return 0;
}