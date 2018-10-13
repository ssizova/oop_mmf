//
// Created by User on 07.10.2018.
//

#ifndef WORD_COUNER_WORDS_READER_H
#define WORD_COUNER_WORDS_READER_H

#include <string>
#include <vector>
#include <map>

std::vector<std::string> Get_lines(const std::string& input);

bool is_separator(const char &symbol);

std::vector<std::string> Parse_into_words(const std::string &line);

std::map<std::string, int32_t> Words_classification(std::vector<std::string> words);

#endif //WORD_COUNER_WORDS_READER_H
