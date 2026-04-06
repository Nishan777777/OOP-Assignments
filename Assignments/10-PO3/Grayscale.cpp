#include "Grayscale.h"

void Grayscale::apply(Grid& pixels) {
    for (auto& row : pixels) {
        for (auto& pixel : row) {
            int avg = (pixel.r + pixel.g + pixel.b) / 3;
            pixel.r = avg;
            pixel.g = avg;
            pixel.b = avg;
        }
    }
}

std::string Grayscale::name() const {
    return "grayscale";
}
