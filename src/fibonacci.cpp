#include "fibonacci.hpp"
#include <stdexcept>

std::vector<unsigned long long> generateFibonacci(size_t n) {
    if (n == 0) {
        throw std::invalid_argument("n must be a positive integer");
    }

    std::vector<unsigned long long> fib;
    fib.reserve(n);

    fib.push_back(0);
    if (n == 1) return fib;

    fib.push_back(1);
    for (size_t i = 2; i < n; ++i) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
    return fib;
}
