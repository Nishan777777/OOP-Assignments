#include "Brighten.h"
#include <algorithm>

void Brighten::apply(Image& image) {
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            Color& c = image.at(x, y);
            c.r = std::min(255, c.r + 40);
            c.g = std::min(255, c.g + 40);
            c.b = std::min(255, c.b + 40);
        }
    }
}

std::string Brighten::name() const {
    return "Brighten";
}