#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Frequency_counter.h"
#include "Words_reader.h"

struct WordDescriptor {
    std::string word;
    int32_t frequency;
    double frequency_percentage;
};


void Print_vector_in_csv (const std::vector<WordDescriptor> &words, const std::string &output) {
    std::ofstream output_file (output);
    int32_t size = words.size();
    output_file << "sep=, "  << std::endl;
    output_file.precision (2);
    for (int32_t i = 0; i < size; ++i)
    {
        output_file << words[i].word << "," << words[i].frequency  << ",";
        output_file << words[i].frequency_percentage << std::endl;
        std::cout << words[i].frequency_percentage << std::endl;
    }
}


int32_t Words_counter (std::map<std::string, int32_t> my_map) {
    int32_t number_of_words = 0;
    for (auto it=my_map.begin(); it != my_map.end(); ++it) {
        number_of_words += it->second;
    }
    return number_of_words;
}


std::vector<double> Frequency_percentage (std::map <std::string, int32_t> my_map) {
    int32_t number_of_words = Words_counter(my_map);
    std::vector<double> percentage;
    for (auto it=my_map.begin(); it != my_map.end(); ++it) {
        percentage.push_back(it->second * 100.0 / number_of_words);
    }
    return percentage;
}


std::vector<WordDescriptor> Sorting (std::map<std::string, int32_t> words) {
    std::vector<double> percents = Frequency_percentage (words);
    std::vector<WordDescriptor> sorted_words;
    WordDescriptor object;
    int32_t i = 0;
    for (auto it = words.begin(); it!=words.end(); ++it) {
        object.word = it->first;
        object.frequency = it->second;
        object.frequency_percentage = percents[i];
        ++i;
        sorted_words.push_back(object);
    }
    std::sort(sorted_words.begin(), sorted_words.end(), [](WordDescriptor d1, WordDescriptor d2){ return d1.frequency > d2.frequency; });
    return sorted_words;
}


void Words_finder ( std::string input,  std::string output) {
    std::vector<std::string> lines = Get_lines(input);
    std::vector<std::string> words_in_vector;
    std::map<std::string, int32_t> words;

    for (std:: size_t i = 0; i  < lines.size(); ++i) {
        words_in_vector = Parse_into_words (lines[i]);
        words = Words_classification (words_in_vector);
    }
    std::vector<WordDescriptor> sorted_words = Sorting(words);
    Print_vector_in_csv (sorted_words, output);

}