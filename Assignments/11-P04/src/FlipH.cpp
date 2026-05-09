#include "FlipH.h"
#include <utility>

void FlipH::apply(Image& image) {
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width() / 2; x++) {
            std::swap(image.at(x, y), image.at(image.width() - 1 - x, y));
        }
    }
}

std::string FlipH::name() const {
    return "FlipH";
}