//
// Created by sofia on 20.04.19.
//
#include <gtest/gtest.h>
#include <iostream>
#include "../CSVParser.h"
#include "../InputIterator.h"
#include "../TupleLibrary.h"

#include <gmock/gmock.h>
#include <fcntl.h>

std::ifstream f("test_file.csv");
int32_t skipped_lines = 0;
char separator = ',';
char scr = '"';


//class CSVParserTests {
//template<typename...Arguments>
//class InputIteratorTests : InputIterator<Arguments...> {
//    std::tuple<int, std::string> lines;
//    bool isEnd = false;
//    bool lastElement = false;
//    int32_t ind = 0;
//};

//
InputIterator<int, std::string> iter(&f, false, separator, scr);
//InputIterator<int, std::string> last_iter(&f, false, separator, scr);


TEST(InputOperator, constructor) {
    EXPECT_THAT(iter.separator, separator);
    EXPECT_THAT(iter.screnning, scr);
    EXPECT_THAT(iter.isEnd, false);
    EXPECT_THAT(iter.lastElement, false);
    EXPECT_THAT(iter.index, 0);
}

CSVParser<int, std::string> p(&f, false, separator, scr);
TEST(Csvparser, constructor) {
    EXPECT_THAT(p.separator, separator);
    EXPECT_THAT(p.file, &f);
    EXPECT_THAT(p.screening, scr);
    EXPECT_THAT(p.skipped_lines, 0);

}

CSVParser<int, std::string> parser(&f, 0, ',', '"');

TEST(Csvparser, begin) {
    auto starter = parser.begin();
    EXPECT_THAT(starter.lastElement, false);
    EXPECT_THAT(starter.index, 1);
    EXPECT_TRUE(starter.separator == ',');
    EXPECT_THAT(starter.screnning, parser.screening);
}


TEST(Csvparser, end) {
    auto finisher = parser.end();

    EXPECT_THAT(finisher.isEnd, true);
    EXPECT_GE(finisher.index, 0);
    EXPECT_THAT(finisher.separator, parser.separator);
    EXPECT_THAT(finisher.screnning, parser.screening);
}
TEST (Integration, parsing_line) {
    std::ifstream f1("test_file.csv");
    std::ifstream f2("test_file.csv");
    std::string first_line_standart;
    std::tuple<int, std::string> first_line_tupleLibrary;

    f2 >> first_line_standart;
//    CSVParser<int, std::string> reader(&f1, false, separator, scr);
    first_line_tupleLibrary = parse<int, std::string>(&f1, separator);
    std::string line = std::to_string(std::get<0>(first_line_tupleLibrary)) + separator +
                       std::get<1>(first_line_tupleLibrary);
    EXPECT_EQ(first_line_standart, line);
}

//TEST(Acceptance,file_content){
//    std::ifstream f1("test_file.csv");
//    std::ifstream f2("test_file.csv");
//    std::string first_line;
//    while (!f1.eof()){
//        f1>>first_line;
//
//    }
//}

int main(int argc, char **argv) {


    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}