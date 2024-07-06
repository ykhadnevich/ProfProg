#include <iostream>
#include "PricePresenter.hpp"

class Milk {
public:
    double getCoefficient() const { return 1.2; }
    double getBasePrice() const { return 2.5; }
};

class Cookies {
public:
    double getCoefficient() const { return 1.5; }
    double getBasePrice() const { return 1.0; }
};

class Pineapple {
public:
    double getCoefficient() const { return 1.8; }
    double getBasePrice() const { return 3.75; }
};

int main() {
    PricePresenter<2> presenter;

    Milk milk;
    Cookies cookies;
    Pineapple pineapple;

    presenter.printTotalPrice(milk, cookies);
    presenter.printTotalPrice(cookies, pineapple);

    return 0;
}
