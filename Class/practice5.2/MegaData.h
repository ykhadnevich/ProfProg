#ifndef MEGADATA_H
#define MEGADATA_H

#include <array>
#include <cstddef>

class MegaData {
public:
    static constexpr size_t SMALL_ARRAY_SIZE = 1024;
    static constexpr size_t BIG_ARRAY_SIZE = 1024 * 1024;
    static constexpr int DEFAULT_VALUE = 0;

    MegaData();

    void reset();

private:
    std::array<float, SMALL_ARRAY_SIZE> smallArray;
    std::array<double, BIG_ARRAY_SIZE> bigArray;
};

#endif // MEGADATA_H
