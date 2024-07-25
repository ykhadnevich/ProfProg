#include "MegaDataPool.h"
#include <stdexcept> // Include <stdexcept> for std::runtime_error

MegaDataPool* MegaDataPool::instance = nullptr;
std::mutex MegaDataPool::mutex; // Define static mutex variable

MegaDataPool::MegaDataPool() {
    // Private constructor
}

MegaDataPool& MegaDataPool::getInstance() {
    // Ensure thread safety with double-checked locking
    if (!instance) {
        std::lock_guard<std::mutex> lock(mutex);
        if (!instance) {
            instance = new MegaDataPool();
            instance->init(2); // Adjust the pool size as needed
        }
    }
    return *instance;
}

void MegaDataPool::init(int poolSize) {
    // Initialize the pool and availability vectors
    pool.reserve(poolSize);
    available.resize(poolSize, true);
    for (int i = 0; i < poolSize; ++i) {
        pool.emplace_back();
    }
}

MegaData& MegaDataPool::acquire() {
    // Acquire a MegaData object from the pool
    std::lock_guard<std::mutex> lock(mutex);
    for (size_t i = 0; i < available.size(); ++i) {
        if (available[i]) {
            available[i] = false;
            return pool[i];
        }
    }
    throw std::runtime_error("No available MegaData objects in the pool");
}

void MegaDataPool::release(MegaData& data) {
    // Release a MegaData object back to the pool
    std::lock_guard<std::mutex> lock(mutex);
    for (size_t i = 0; i < pool.size(); ++i) {
        if (&data == &pool[i]) {
            if (available[i]) {
                throw std::runtime_error("This MegaData object is already released");
            }
            available[i] = true;
            return;
        }
    }
    throw std::runtime_error("This MegaData object does not belong to the pool");
}