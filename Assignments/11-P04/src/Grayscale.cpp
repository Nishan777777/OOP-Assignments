#include "Grayscale.h"

void Grayscale::apply(Image& image) {
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            Color& c = image.at(x, y);
            int gray = (c.r + c.g + c.b) / 3;
            c.r = gray;
            c.g = gray;
            c.b = gray;
        }
    }
}

std::string Grayscale::name() const {
    return "Grayscale";
}