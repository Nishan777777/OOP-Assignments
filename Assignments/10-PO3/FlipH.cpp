#include "FlipH.h"

#include <algorithm>

void FlipH::apply(Grid& pixels) {
    for (auto& row : pixels) {
        std::reverse(row.begin(), row.end());
    }
}

std::string FlipH::name() const {
    return "flipH";
}
