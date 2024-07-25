#ifndef CONCEPTS_HPP
#define CONCEPTS_HPP

#include <concepts>

template<typename T>
concept HasPriceInfo = requires(T obj) {
    { obj.getCoefficient() } -> std::convertible_to<double>;
    { obj.getBasePrice() } -> std::convertible_to<double>;
};

#endif // CONCEPTS_HPP
