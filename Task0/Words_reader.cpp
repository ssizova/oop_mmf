#include <string>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include "Words_reader.h"

bool is_separator(const char &symbol) {
    return (!(std::isdigit(symbol) || std::isalpha(symbol)));
}

std::map<std::string, int32_t> Words_classification(std::vector<std::string> words) {
    std::map<std::string, int32_t> frequency;

    for (auto& word : words) {
        auto it = frequency.find(word);
        if (it != frequency.end()) {
            it->second += 1;
        } else {
            frequency[word] = 1;
        }
    }
    return frequency;
}

std::vector<std::string> Get_lines(const std::string& input) {
    std::ifstream input_file(input);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(input_file, line)) {
        lines.push_back(line);
    }
    return lines;
}

std::vector<std::string> Parse_into_words(const std::string &line) {
    char symbol = 0;
    std::string word;
    std::vector<std::string> words;
    for (std::size_t i = 0; i < line.length(); ++i) {
        symbol = line[i];
        if (!is_separator(symbol)) {
            word += symbol;
            if (i == line.length() - 1) {
                words.push_back(word);
            }
        } else {
            if (!word.empty()) {
                words.push_back(word);
            }
            word = "";
        }
    }
    return words;
}