#pragma once
#include <string>
#include <format>

class LegacyCalculator {
public:
    LegacyCalculator(double in_megaDelta, double in_megaMultiplier) {
        megaDelta = in_megaDelta;
        megaMultiplier = in_megaMultiplier;
    }

    double calculatePricePart1() const {
        return STRANGE_VAL1 - megaDelta;
    }

    double calculatePricePart2() const {
        return STRANGE_VAL2 * megaMultiplier + 1 - megaDelta;
    }

    double getOurTheMostAndMinimalValue() const {
        return megaDelta * megaMultiplier;
    }

    std::string getSomeDocumentRepresentation() const {
    return "The man " + std::to_string(STRANGE_VAL1 - megaDelta) + " who sold the " + std::to_string(megaMultiplier * STRANGE_VAL2) + " world";
}

private:
    double megaDelta;
    double megaMultiplier;
    static constexpr auto STRANGE_VAL1 = 6.0;
    static constexpr auto STRANGE_VAL2 = 13.0;
};
