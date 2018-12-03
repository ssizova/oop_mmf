#include <iostream>
#include <cstdint>
#include <memory>
#include <strings.h>
#include <iterator>
#include "Functions.h"



int main() {
    constexpr int32_t N = 10;
    constexpr double h = double(10) / (2* N - 1);
    std::cout << IntegrateSimpson<2*N>()<<std::endl;
    return 0;
}