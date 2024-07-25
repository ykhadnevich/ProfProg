#include "Helpers.hpp"
#include <algorithm> // for std::max_element

double dummyFunc(double x) {
    return x > 0 ? x : 0;
}

std::string repeatString(const std::vector<int>& vec, const std::string& str) {
    if (vec.empty()) return "";
    int max_elem = *std::max_element(vec.begin(), vec.end());
    std::string result;
    for (int i = 0; i < max_elem; ++i) {
        result += str;
    }
    return result;
}
