#include <gtest/gtest.h>
#include "../Functions.h"

TEST(Sonya, IsSonyaLalka) {
    ASSERT_EQ(-1.0, -1);
}

TEST(function, myFunction) {
    auto f = my_function<double>;
    EXPECT_EQ(f(10), 100);
}

TEST(Integrate, Simpsonrule) {
    auto f = my_function<double>;
    EXPECT_NEAR(Integrate(f), 83.3333,0.0001);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}