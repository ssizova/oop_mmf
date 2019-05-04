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


class CSVParserTest : public ::testing::Test {
public:
    CSVParser<int, std::string> *parser;
protected:
    virtual void SetUp() {
        parser = new CSVParser<int, std::string>(&f, 0, ',', '"');
    }

};


InputIterator<int, std::string> iter(&f, false, separator, scr);


TEST(InputOperator, constructor) {
    EXPECT_THAT(iter.separator, separator);
    EXPECT_THAT(iter.screnning, scr);
    EXPECT_THAT(iter.isEnd, false);
    EXPECT_THAT(iter.lastElement, false);
    EXPECT_THAT(iter.index, 0);
}

CSVParser<int, std::string> p(&f, false, separator, scr);

TEST_F(CSVParserTest, constructor) {
    EXPECT_THAT(p.separator, separator);
    EXPECT_THAT(p.file, &f);
    EXPECT_THAT(p.screening, scr);
    EXPECT_THAT(p.skipped_lines, 0);

}


TEST_F(CSVParserTest, begin) {
    auto starter = parser->begin();
    EXPECT_THAT(starter.lastElement, false);
    EXPECT_THAT(starter.index, 1);
    EXPECT_TRUE(starter.separator == ',');
    EXPECT_THAT(starter.screnning, parser->screening);
}


TEST_F(CSVParserTest, end) {
    auto finisher = parser->end();

    EXPECT_THAT(finisher.isEnd, true);
    EXPECT_GE(finisher.index, 0);
    EXPECT_THAT(finisher.separator, parser->separator);
    EXPECT_THAT(finisher.screnning, parser->screening);
}

TEST (Integration, parsing_line) {
    std::ifstream f1("test_file.csv");
    std::ifstream f2("test_file.csv");
    std::string first_line_standart;
    std::vector<std::tuple<int,std::string>> tuples = {
            std::tuple<int,std::string>(1, "Ivanov"),
            std::tuple<int,std::string>(2, "Petrov"),
            std::tuple<int,std::string>(3, "Sidorov")
    };
    CSVParser<int,std::string> parser(&f1,0,',','"');
    std::tuple<int, std::string> first_line_tupleLibrary;

    int j = 0;
    for (auto i = parser.begin(); i != parser.end(); ++i) {
        EXPECT_EQ(tuples[j],*i);
        ++j;
    }
}



int main(int argc, char **argv) {


    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}