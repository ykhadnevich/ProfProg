#include "Pizza.h"
#include "PizzaBuilder.h"
#include "PizzaDirector.h"
#include <iostream>
#include <cassert>

void testPizzaClass() {
    Pizza pizza;
    pizza.addIngredient("Cheese", 1.5);
    pizza.addIngredient("Pepperoni", 2.0);

    assert(pizza.getTotalCost() == 3.5);
    assert(pizza.getIngredients().size() == 2);
    assert(pizza.getIngredients()[0].first == "Cheese");
    assert(pizza.getIngredients()[0].second == 1.5);
    assert(pizza.getIngredients()[1].first == "Pepperoni");
    assert(pizza.getIngredients()[1].second == 2.0);
}

void testPizzaBuilderClass() {
    PizzaBuilder builder;
    builder.addIngredient("Cheese");
    builder.addIngredient("Ham");

    Pizza pizza = builder.getPizza();
    assert(pizza.getTotalCost() == 4.0);
    assert(pizza.getIngredients().size() == 2);
    assert(pizza.getIngredients()[0].first == "Cheese");
    assert(pizza.getIngredients()[0].second == 1.5);
    assert(pizza.getIngredients()[1].first == "Ham");
    assert(pizza.getIngredients()[1].second == 2.5);
}

void testPizzaDirectorClass() {
    PizzaBuilder builder;
    PizzaDirector director;
    director.constructPizza(builder);
    
    Pizza pizza = builder.getPizza();
    std::cout << "Total cost: $" << pizza.getTotalCost() << std::endl;
    for (const auto& ingredient : pizza.getIngredients()) {
        std::cout << ingredient.first << ": $" << ingredient.second << std::endl;
    }
}

int main() {
    testPizzaClass();
    testPizzaBuilderClass();
    std::cout << "All tests passed!" << std::endl;

    PizzaBuilder builder;
    PizzaDirector director;
    director.constructPizza(builder);

    Pizza pizza = builder.getPizza();
    std::cout << "Your pizza ingredients and cost:" << std::endl;
    for (const auto& ingredient : pizza.getIngredients()) {
        std::cout << ingredient.first << ": $" << ingredient.second << std::endl;
    }
    std::cout << "Total cost: $" << pizza.getTotalCost() << std::endl;

    return 0;
}
