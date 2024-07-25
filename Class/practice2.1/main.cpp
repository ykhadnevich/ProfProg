#include <iostream>
#include <string>
#include <vector>
#include <ranges>

int main()
{
    // Read input
    std::cout << "Enter the list of numbers separated by comma:" << std::endl;
    std::string inputString;
    std::getline(std::cin, inputString);

    // Define delimiter
    constexpr std::string_view delimiter(",");

    // Process input
    auto filteredValues = inputString
        | std::views::split(delimiter)
        | std::views::transform([](const auto& subrange) {
            std::string str;
            for (char c : subrange) {
                str += c;
            }
            try {
                return std::stod(str);
            } catch (...) {
                return 0.0;
            }
    })
    | std::views::filter([](double val) { return val < 0; })
    | std::ranges::to<std::vector<double>>();


    // Output result
    if (filteredValues.empty()) {
        std::cout << "No negative values in the list or incorrect input format" << std::endl;
    } else {
        std::cout << "Result is " << *std::max_element(filteredValues.begin(), filteredValues.end()) << std::endl;
    }

    return 0;
}
