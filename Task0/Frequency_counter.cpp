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


void Print_vector_in_csv(const std::vector<WordDescriptor> &words, const std::string &output) {
    std::ofstream output_file(output);
    int32_t size = words.size();
    output_file << "sep=, " << std::endl;
    output_file.precision(2);
    for (int32_t i = 0; i < size; ++i) {
        output_file << words[i].word << "," << words[i].frequency << ",";
        output_file << words[i].frequency_percentage << std::endl;
    }
}


int32_t Words_counter(std::map<std::string, int32_t> my_map) {
    int32_t number_of_words = 0;
    for (auto &kv : my_map) {
        number_of_words += kv.second;
    }
    return number_of_words;
}


std::vector<double> Frequency_percentage(std::map<std::string, int32_t> my_map) {
    int32_t number_of_words = Words_counter(my_map);
    std::vector<double> percentage;
    percentage.reserve(my_map.size());

    for (auto &key_value : my_map) {
        percentage.push_back(key_value.second * 100.0 / number_of_words);
    }
    return percentage;
}


std::vector<WordDescriptor> Sorting(std::map<std::string, int32_t> words) {
    std::vector<double> percents = Frequency_percentage(words);
    std::vector<WordDescriptor> sorted_words;
    WordDescriptor object;
    int32_t i = 0;

    for (auto &kv : words) {
        object.word = kv.first;
        object.frequency = kv.second;
        object.frequency_percentage = percents[i];
        ++i;
        sorted_words.push_back(object);
    }
    std::sort(sorted_words.begin(), sorted_words.end(),
              [](WordDescriptor d1, WordDescriptor d2) { return d1.frequency > d2.frequency; });
    return sorted_words;
}


void Words_finder(const std::string &input, std::string output) {
    std::vector<std::string> lines = Get_lines(input);
    std::vector<std::string> words_in_vector;

    for (auto &line : lines) {
        auto new_vector = Parse_into_words(line);
        words_in_vector.insert(words_in_vector.end(), new_vector.begin(), new_vector.end());
    }

    auto words = Words_classification(words_in_vector);
    std::vector<WordDescriptor> sorted_words = Sorting(words);
    Print_vector_in_csv(sorted_words, output);

}