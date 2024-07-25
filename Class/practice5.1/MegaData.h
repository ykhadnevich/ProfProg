#ifndef MEGA_DATA_H
#define MEGA_DATA_H

#include <array>
#include <cstddef>  // Include cstddef for size_t

class MegaData {
public:
    static constexpr std::size_t SMALL_ARRAY_SIZE = 16; // Reduced size for testing
    static constexpr std::size_t BIG_ARRAY_SIZE = 256; // Reduced size for testing
    static constexpr double DEFAULT_VALUE = 42.0;

    MegaData();
    void reset();

    std::array<float, SMALL_ARRAY_SIZE> smallArray;
    std::array<double, BIG_ARRAY_SIZE> bigArray;
};

#endif
