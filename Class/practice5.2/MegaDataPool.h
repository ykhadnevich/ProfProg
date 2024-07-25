#pragma once

#include "MegaData.h"
#include <vector>
#include <mutex>

class MegaDataPool {
private:
    static MegaDataPool* instance;
    static std::mutex mutex; // Static mutex variable
    std::vector<MegaData> pool;
    std::vector<bool> available;

    MegaDataPool(); // Private constructor to prevent instantiation
    void init(int poolSize);

public:
    static MegaDataPool& getInstance(); // Static method to access singleton instance
    MegaData& acquire(); // Acquire a MegaData object from the pool
    void release(MegaData& data); // Release a MegaData object back to the pool
};