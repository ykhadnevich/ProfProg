#include "MegaData.h"
#include <iostream>

MegaData::MegaData() {
    std::cout << "MegaData constructor called at address: " << this << std::endl;
    smallArray.fill(DEFAULT_VALUE);
    bigArray.fill(DEFAULT_VALUE);
    std::cout << "MegaData arrays initialized at address: " << this << std::endl;
}

void MegaData::reset() {
    std::cout << "MegaData reset called at address: " << this << std::endl;
    smallArray.fill(DEFAULT_VALUE);
    bigArray.fill(DEFAULT_VALUE);
}
