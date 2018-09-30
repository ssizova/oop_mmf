#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

struct WordDescriptor
{
	std::string word;
	int32_t frequency;
	double frequency_percentage;
};


bool is_separator(char symbol) {
	return (!(std::isdigit(symbol) || std::isalpha(symbol)));
}


void Print_vector_in_csv (std::vector<WordDescriptor> words, std::string output) {
	std::ofstream output_file (output);
	int32_t size = words.size();
	output_file << "sep=," << std::endl;
	for (int32_t i = 0; i < size; ++i)
	{
		output_file << words[i].word << "," << words[i].frequency << ",";
		output_file.precision (4);
		output_file << words[i].frequency_percentage << std::endl;
	}
}


std::vector<std::string> Parse_into_words (std::string line) {
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
			if (word !="") {
				words.push_back(word);
			}
			word = "";
		}
	}
	return words;
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
	for (int32_t i = 0; i < words.size(); ++i) {
		std::map<std::string,int32_t>:: iterator it = frequency.find(words[i]);
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
    	percentage.push_back(it->second * 100.0 / number_of_words);
	}
	return percentage;
}


std::vector<WordDescriptor> Sorting (std::map<std::string, int32_t> words) {
	std::vector<double> percents = Frequency_percentage (words);
	std::vector<WordDescriptor> sorted_words;
	WordDescriptor object;
	int32_t i = 0;
	for (std::map<std::string,int32_t>::iterator it = words.begin(); it!=words.end(); ++it) {
    	object.word = it->first;
    	object.frequency = it->second;
    	object.frequency_percentage = percents[i];
    	++i;
    	sorted_words.push_back(object);
	}
	std::sort(sorted_words.begin(), sorted_words.end(), [](WordDescriptor d1, WordDescriptor d2){ return d1.frequency > d2.frequency; });
	return sorted_words;
}


void Words_finder (std::string input, std::string output) {
	std::vector<std::string> lines = Get_lines(input); 
	std::vector<std::string> words_in_vector;
	std::map<std::string, int32_t> words;


	
	for (int32_t i = 0; i < lines.size(); ++i) {
		words_in_vector = Parse_into_words (lines[i]);
		words = Words_classification (words, words_in_vector);
	}
	std::vector<WordDescriptor> sorted_words = Sorting(words);
 	Print_vector_in_csv (sorted_words,output);

}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::string input = "";
	std::string output = "";
	std::cin >> input >> output ;
   	Words_finder(input, output);
	return 0;
}