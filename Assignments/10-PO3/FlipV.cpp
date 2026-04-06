#include "FlipV.h"

#include <algorithm>

void FlipV::apply(Grid& pixels) {
    std::reverse(pixels.begin(), pixels.end());
}

std::string FlipV::name() const {
    return "flipV";
}
