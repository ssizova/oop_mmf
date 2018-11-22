#include <memory>
#include <bits/unique_ptr.h>
#include <strings.h>
template <class T>
class Array {
    std::unique_ptr<T[]> data;
public:
    explicit Array(uint32_t size) : data(std::make_unique<T[]>(size)) {
    }
    T Get(uint32_t) {
        return data.get()[index];
    }
    void Set(uint32_t index, T value){
        data.get()[index] = value;
    }

};