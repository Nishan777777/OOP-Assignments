#include "Rotate.h"

void Rotate::apply(Image& image) {
    Image rotated(image.height(), image.width());

    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            rotated.at(image.height() - 1 - y, x) = image.at(x, y);
        }
    }

    image = rotated;
}

std::string Rotate::name() const {
    return "Rotate";
}