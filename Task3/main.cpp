#include <iostream>
#include <cstdint>
#include <memory>
#include <strings.h>
#include <iterator>
#include "Functions.h"


int main() {
    constexpr int32_t N = 100;
    std::cout << IntegrateSimpson<2 * N + 1>() << std::endl;
    return 0;
}