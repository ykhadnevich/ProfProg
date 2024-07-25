#pragma once
#include "Pizza.h"
#include <map>

class PizzaBuilder {
public:
    PizzaBuilder();
    void addIngredient(const std::string& ingredient);
    Pizza getPizza() const;

private:
    Pizza pizza;
    std::map<std::string, double> availableIngredients;
    void loadIngredients();
};
