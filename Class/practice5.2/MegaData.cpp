#include "MegaData.h"

MegaData::MegaData() {
    smallArray.fill(DEFAULT_VALUE);
    bigArray.fill(DEFAULT_VALUE);
}

void MegaData::reset() {
    smallArray.fill(DEFAULT_VALUE);
    bigArray.fill(DEFAULT_VALUE);
}
