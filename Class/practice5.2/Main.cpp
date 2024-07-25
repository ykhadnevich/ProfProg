// Main.cpp

#include "MegaDataPool.h"
#include <iostream>

int main() {
    std::cout << "Acquiring two objects...\n";
    MegaDataPool& pool = MegaDataPool::getInstance(); 
    MegaData& obj1 = pool.acquire(); 
    MegaData& obj2 = pool.acquire();

    std::cout << "Objects acquired.\n";

    std::cout << "Releasing objects...\n";
    pool.release(obj1); 
    pool.release(obj2);
    std::cout << "Objects released.\n";

    return 0;
}
