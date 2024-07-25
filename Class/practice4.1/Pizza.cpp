#include "Pizza.h"

void Pizza::addIngredient(const std::string& ingredient, double cost) {
    ingredients.emplace_back(ingredient, cost);
}

double Pizza::getTotalCost() const {
    double total = 0.0;
    for (const auto& ingredient : ingredients) {
        total += ingredient.second;
    }
    return total;
}

std::vector<std::pair<std::string, double>> Pizza::getIngredients() const {
    return ingredients;
}
