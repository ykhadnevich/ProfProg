#pragma once
#include <vector>
#include <string>
#include <utility>

class Pizza {
public:
    void addIngredient(const std::string& ingredient, double cost);
    double getTotalCost() const;
    std::vector<std::pair<std::string, double>> getIngredients() const;

private:
    std::vector<std::pair<std::string, double>> ingredients;
};


