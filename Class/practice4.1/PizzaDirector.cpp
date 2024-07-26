#include "PizzaDirector.h"
#include <iostream>
#include <format> // For std::format and std::print

// Define a named constant for the command
constexpr auto DONE_COMMAND = "done";

void PizzaDirector::constructPizza(PizzaBuilder& builder) {
    std::string input;
    std::print("Enter ingredients (type '{}' to finish):\n", DONE_COMMAND);

    while (true) {
        std::cin >> input;
        if (input == DONE_COMMAND) {
            break;
        }
        try {
            builder.addIngredient(input);
            std::print("{} added.\n", input);
        } catch (const std::exception& e) {
            std::print("{}\n", e.what());
        }
    }
}
