#include <gtest/gtest.h>
#include "../Functions.h"
#include "../Array.h"
#include <gmock/gmock.h>

template<typename argument>
constexpr argument TestFunction(argument x) {
    return x;
}

TEST(function, MyFunction) {
    auto f = MyFunction<double>;
    EXPECT_EQ(f(1), 1);
}

TEST(makeArray, make_array) {
    constexpr int32_t N = 5;
    constexpr auto a = MakeArray<N>(TestFunction<double>);
    EXPECT_THAT(a, ::testing::ElementsAre(-1.0,- 0.5, 0, 0.5, 1.0));
}

TEST(makeCoeffs, make_coeffs) {
    constexpr int32_t N = 5;
    constexpr double h = double(2) / (N - 1);
    constexpr std::array<double, N> a = {1, 1, 1, 1, 1};
    constexpr auto coeffs = MakeCoeffs<N, 0>(a);
    EXPECT_THAT(coeffs, ::testing::ElementsAre( h / 3, 4 * h / 3, 2 * h / 3, 4 * h / 3, h / 3));
}

TEST(summa, Sum) {
    constexpr int32_t N = 5;
    constexpr std::array<double, N> a = {1, 1, 1, 1, 1};
    constexpr auto s = Sum<N, 0>(a);

    EXPECT_EQ(s, 5);
}


TEST(Integrate, Simpsonrule) {
    auto f = MyFunction<double>;
    EXPECT_NEAR(IntegrateSimpson<150>(), 0.4, 0.007);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}