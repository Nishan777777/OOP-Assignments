#include "Rotate.h"

Rotate::Rotate(int degrees) : degrees(degrees) {}

void Rotate::apply(Grid& pixels) {
    if (pixels.empty() || pixels[0].empty()) return;

    int oldH = static_cast<int>(pixels.size());
    int oldW = static_cast<int>(pixels[0].size());

    if (degrees == 0) {
        return;
    }
    else if (degrees == 90) {
        Grid rotated(oldW, Row(oldH));
        for (int r = 0; r < oldH; ++r) {
            for (int c = 0; c < oldW; ++c) {
                rotated[c][oldH - 1 - r] = pixels[r][c];
            }
        }
        pixels = rotated;
    }
    else if (degrees == 180) {
        Grid rotated(oldH, Row(oldW));
        for (int r = 0; r < oldH; ++r) {
            for (int c = 0; c < oldW; ++c) {
                rotated[oldH - 1 - r][oldW - 1 - c] = pixels[r][c];
            }
        }
        pixels = rotated;
    }
    else if (degrees == 270) {
        Grid rotated(oldW, Row(oldH));
        for (int r = 0; r < oldH; ++r) {
            for (int c = 0; c < oldW; ++c) {
                rotated[oldW - 1 - c][r] = pixels[r][c];
            }
        }
        pixels = rotated;
    }
}

std::string Rotate::name() const {
    return "rotate(" + std::to_string(degrees) + ")";
}
