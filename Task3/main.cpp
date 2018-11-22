#include <iostream>
#include <iostream>
#include <cstdint>
#include <memory>
#include <strings.h>
#include <memory>
#include "Array.cpp"
//template <class T>
//        erfef



template<typename argument>
constexpr argument my_function(argument x) {
    return x * x ;//- 7 * (1 + x * x / 2 + x * x * x * x / 24);
}

template<typename Function>
constexpr double Integrate(Function my_function) {
    constexpr int32_t leftNode = -5;
    constexpr int32_t rightNode = 5;

    constexpr uint32_t n = 10;

    //constexpr Array<double> nodes = Array<double>(n);
    return (rightNode - leftNode) / 6.0 * (my_function(leftNode) + 4 * my_function((leftNode + rightNode) / 2.0) +
                                         my_function(rightNode));


}
//template<size_t index> struct MetaFunc {
//    enum { value = index + 1 };
//};
//
//void test() {
//    const size_t count = 5;
//    typedef generate_array<count, MetaFunc>::result A;
//
//    for (size_t i=0; i<count; ++i)
//        std::cout << A::data[i] << "\n";
//}

int main() {
    Array<double> ny(5);
    auto f = my_function<double>;
    //auto result = Integrate(f);
    std::cout << Integrate(f);

    return 0;
}