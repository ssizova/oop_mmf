#ifndef WORD_COUNER_FREQUENCY_COUNTER_H
#define WORD_COUNER_FREQUENCY_COUNTER_H

#include <vector>
#include <string>
#include <map>

struct WordDescriptor;

void Print_vector_in_csv(const std::vector<WordDescriptor> &words, const std::string &output);

int32_t Words_counter(std::map<std::string, int32_t> my_map);

std::vector<double> Frequency_percentage(std::map<std::string, int32_t> my_map);

std::vector<WordDescriptor> Sorting(std::map<std::string, int32_t> words);

void Words_finder(const std::string& input, std::string output);

#endif //WORD_COUNER_FREQUENCY_COUNTER_H
