#ifndef MEGA_DATA_POOL_H
#define MEGA_DATA_POOL_H

#include "MegaData.h"
#include <vector>

class MegaDataPool {
public:
    MegaDataPool(std::size_t poolSize);

    MegaData& acquire();
    void release(MegaData& data);

    std::size_t size() const;
    std::size_t usedSize() const;

private:
    std::size_t poolSize;
    std::vector<MegaData> pool;
    std::vector<bool> available;
};

#endif
