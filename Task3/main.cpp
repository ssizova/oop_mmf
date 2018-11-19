#include <iostream>
#include <iostream>
#include <cstdint>
#include <memory>
#include <strings.h>
#include <memory>
//template <class T>
//        erfef

int32_t leftNode = -5;
int32_t rightNode = 5;

template<typename argument>
constexpr argument my_function(argument x) {
    return x * x ;//- 7 * (1 + x * x / 2 + x * x * x * x / 24);
}

template<typename Function>
constexpr double Integrate(Function my_function) {
    return (rightNode - leftNode) / 6.0 * (my_function(leftNode) + 4 * my_function((leftNode + rightNode) / 2.0) +
                                           my_function(rightNode));
}


int main() {
    auto f = my_function<double>;
    //auto result = Integrate(f);
    std::cout << Integrate(f);

    return 0;
}