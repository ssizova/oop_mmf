#include <gtest/gtest.h>
#include "functionmaker.h"
#include "mainwindow.h"
#include <stdint-gcc.h>

#include <fcntl.h>
#include <vector>

#include <QTest>

class FunctionMakerTest : public ::testing::Test {
public:
    FunctionMaker *fun;

protected:
    virtual void SetUp() {
        fun = new FunctionMaker(0,0,1,2);
    }

};


class MainWindowTest: public ::testing::Test {
public:
    MainWindow *window;

protected:
    virtual void SetUp() {
        window = new MainWindow(nullptr);
    }

};

TEST_F(FunctionMakerTest, constructor) {
    auto x = fun->nodes;
    auto y = fun->function_points;
    EXPECT_EQ(x[0], -1);
    EXPECT_EQ(x[1], 0);
    EXPECT_EQ(x[2], 1);

    EXPECT_EQ(y[0],1);
    EXPECT_EQ(y[1],1);
    EXPECT_EQ(y[2],1);
}

TEST_F(FunctionMakerTest, Makenodes){
    auto x = fun->MakeNodes(1);
    EXPECT_EQ(x[0],-1);
    EXPECT_EQ(x[1],1);
}

TEST_F(FunctionMakerTest,CalcFunction){
    auto x = fun->nodes;
    std::vector<double> coeffs = {0,0,1};
    auto y = fun->CalcFunction(x,coeffs);
    EXPECT_EQ(y[0],1);
    EXPECT_EQ(y[1],1);
    EXPECT_EQ(y[2],1);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
