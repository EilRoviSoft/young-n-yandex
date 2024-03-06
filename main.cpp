#include <iostream>
#include <cstdint>

namespace util {
    template <class _T>
    _T read(std::istream& is = std::cin) {
        _T temp;
        is >> temp;
        return temp;
    }
}

int main() {
    
}