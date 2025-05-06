#include "palindrome.hpp"
#include <string>
#include <stdexcept>

bool isPalindrome(int number) {
    if (number < 0) {
        throw std::invalid_argument("Negative numbers are not supported");
    }

    std::string str = std::to_string(number);
    size_t left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) return false;
        ++left;
        --right;
    }
    return true;
}
