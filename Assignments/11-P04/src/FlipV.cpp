#include "FlipV.h"
#include <utility>

void FlipV::apply(Image& image) {
    for (int y = 0; y < image.height() / 2; y++) {
        for (int x = 0; x < image.width(); x++) {
            std::swap(image.at(x, y), image.at(x, image.height() - 1 - y));
        }
    }
}

std::string FlipV::name() const {
    return "FlipV";
}