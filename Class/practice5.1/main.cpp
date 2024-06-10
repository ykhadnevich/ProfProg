#include "MegaDataPool.h"
#include <iostream>
#include <cassert>

void testMegaDataPool() {
    std::cout << "testMegaDataPool called\n";
    std::cout << "Creating MegaDataPool\n";
    MegaDataPool pool(2); // This is the line causing the issue, based on the GDB output
    std::cout << "MegaDataPool created\n";

    MegaData& obj1 = pool.acquire();
    MegaData& obj2 = pool.acquire();

    std::cout << "Acquired two objects\n";

    pool.release(obj1);
    pool.release(obj2);

    std::cout << "Released both objects\n";
}

int main() {
    std::cout << "main started\n";
    testMegaDataPool();
    std::cout << "main finished\n";
    return 0;
}
