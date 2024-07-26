#include "PizzaBuilder.h"
#include <fstream>
#include <stdexcept>

PizzaBuilder::PizzaBuilder() {
    loadIngredients();
}

void PizzaBuilder::loadIngredients() {
    std::ifstream file("ingredients.txt");
    if (!file) {
        throw std::runtime_error("Could not open ingredients file");
    }

    std::string ingredient;
    double cost;
    while (file >> ingredient >> cost) {
        availableIngredients[ingredient] = cost;
    }
}

void PizzaBuilder::addIngredient(const std::string& ingredient) {
    if (availableIngredients.find(ingredient) != availableIngredients.end()) {
        pizza.addIngredient(ingredient, availableIngredients[ingredient]);
    } else {
        throw std::invalid_argument("Ingredient not available");
    }
}

[[nodiscard]] Pizza PizzaBuilder::getPizza() {
    Pizza tempPizza = pizza; // Create a copy of the pizza
    pizza = Pizza(); // Reset the pizza object to its default state
    return tempPizza;
}
