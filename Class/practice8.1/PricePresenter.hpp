#ifndef PRICEPRESENTER_HPP
#define PRICEPRESENTER_HPP

#include <iostream>
#include <concepts>

template<typename T>
concept HasPriceInfo = requires(T obj) {
    { obj.getCoefficient() } -> std::convertible_to<double>;
    { obj.getBasePrice() } -> std::convertible_to<double>;
};

template<size_t PRIORITY>
class PricePresenter {
public:
    template<HasPriceInfo T1, HasPriceInfo T2>
    void printTotalPrice(const T1& obj1, const T2& obj2) const {
        double totalPrice = PRIORITY * obj1.getCoefficient() * obj1.getBasePrice() +
                            obj2.getCoefficient() * obj2.getBasePrice();
        std::cout << "Total Price: " << totalPrice << std::endl;
    }
};

#endif // PRICEPRESENTER_HPP
