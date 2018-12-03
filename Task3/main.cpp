#include <iostream>
#include <cstdint>
#include <memory>
#include <strings.h>
#include <iterator>
#include "Functions.h"
//#include "Array.cpp"


int main() {
    constexpr auto N = 21;
//    constexpr auto f = my_function<double>;
    std::cout << IntegrateSimpson<N>();
    return 0;
}