#include <iostream>
#include <cstdint>
#include <memory>
#include <strings.h>
#include "Functions.h"


int main() {
    auto f = my_function<double>;
    //auto result = Integrate(f);
    std::cout << Integrate(f);
    return 0;
}