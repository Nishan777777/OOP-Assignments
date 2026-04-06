#include "Blur.h"

#include <algorithm>

void Blur::apply(Grid& pixels) {
    if (pixels.empty() || pixels[0].empty()) return;

    Grid original = pixels;
    int height = static_cast<int>(original.size());
    int width = static_cast<int>(original[0].size());

    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            int sumR = 0, sumG = 0, sumB = 0, count = 0;

            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    int rr = std::clamp(r + dr, 0, height - 1);
                    int cc = std::clamp(c + dc, 0, width - 1);
                    sumR += original[rr][cc].r;
                    sumG += original[rr][cc].g;
                    sumB += original[rr][cc].b;
                    ++count;
                }
            }

            pixels[r][c].r = sumR / count;
            pixels[r][c].g = sumG / count;
            pixels[r][c].b = sumB / count;
        }
    }
}

std::string Blur::name() const {
    return "blur";
}
