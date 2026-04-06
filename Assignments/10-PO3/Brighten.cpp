#include "Brighten.h"

Brighten::Brighten(int amount) : amount(amount) {}

int Brighten::clamp(int value) {
    if (value < 0) return 0;
    if (value > 255) return 255;
    return value;
}

void Brighten::apply(Grid& pixels) {
    for (auto& row : pixels) {
        for (auto& pixel : row) {
            pixel.r = clamp(pixel.r + amount);
            pixel.g = clamp(pixel.g + amount);
            pixel.b = clamp(pixel.b + amount);
        }
    }
}

std::string Brighten::name() const {
    return "brighten(" + std::to_string(amount) + ")";
}
