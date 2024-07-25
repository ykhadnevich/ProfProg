#include "MegaDataPool.h"
#include <iostream>
#include <algorithm> // Include algorithm for std::count

MegaDataPool::MegaDataPool(std::size_t poolSize) : poolSize(poolSize), pool(poolSize), available(poolSize, true) {
    std::cout << "MegaDataPool constructor called with pool size: " << poolSize << "\n";
    std::cout << "Pool and availability vectors initialized.\n";
    std::cout << "MegaDataPool instance address: " << this << std::endl;
}

MegaData& MegaDataPool::acquire() {
    std::cout << "Acquire called\n";
    for (std::size_t i = 0; i < poolSize; ++i) {
        if (available[i]) {
            available[i] = false;
            std::cout << "Acquired object at index: " << i << "\n";
            return pool[i];
        }
    }
    throw std::runtime_error("No available MegaData objects in the pool");
}

void MegaDataPool::release(MegaData& data) {
    std::cout << "Release called\n";
    for (std::size_t i = 0; i < poolSize; ++i) {
        if (&pool[i] == &data) {
            if (!available[i]) {
                available[i] = true;
                data.reset();
                std::cout << "Released object at index: " << i << "\n";
                return;
            } else {
                std::cout << "Error: This MegaData object is already released\n";
                throw std::runtime_error("This MegaData object is already released");
            }
        }
    }
    std::cout << "Error: This MegaData object does not belong to the pool\n";
    throw std::runtime_error("This MegaData object does not belong to the pool");
}

std::size_t MegaDataPool::size() const {
    std::cout << "size() called\n";
    return poolSize;
}

std::size_t MegaDataPool::usedSize() const {
    std::cout << "usedSize() called\n";
    return std::count(available.begin(), available.end(), false);
}
