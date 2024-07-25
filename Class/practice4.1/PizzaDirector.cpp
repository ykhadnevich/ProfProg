#include "PizzaDirector.h"
#include <iostream>

void PizzaDirector::constructPizza(PizzaBuilder& builder) {
    std::string input;
    std::cout << "Enter ingredients (type 'done' to finish):" << std::endl;
    while (true) {
        std::cin >> input;
        if (input == "done") {
            break;
        }
        try {
            builder.addIngredient(input);
            std::cout << input << " added." << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}
