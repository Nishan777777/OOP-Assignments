#include "Image.h"

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {
    std::string nextToken(std::istream& in) {
        std::string token;
        while (in >> token) {
            if (!token.empty() && token[0] == '#') {
                std::string discard;
                std::getline(in, discard);
                continue;
            }
            return token;
        }
        return "";
    }
}

void Image::load(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin) {
        throw std::runtime_error("Error: could not open input file '" + filename + "'");
    }

    std::string magic = nextToken(fin);
    if (magic != "P3") {
        throw std::runtime_error("Error: only P3 PPM files are supported");
    }

    std::string widthToken = nextToken(fin);
    std::string heightToken = nextToken(fin);
    std::string maxToken = nextToken(fin);

    if (widthToken.empty() || heightToken.empty() || maxToken.empty()) {
        throw std::runtime_error("Error: invalid PPM header");
    }

    int w = std::stoi(widthToken);
    int h = std::stoi(heightToken);
    int maxVal = std::stoi(maxToken);

    if (w <= 0 || h <= 0) {
        throw std::runtime_error("Error: invalid image dimensions");
    }
    if (maxVal != 255) {
        throw std::runtime_error("Error: max color value must be 255");
    }

    pixels.assign(h, Row(w));

    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c) {
            std::string rs = nextToken(fin);
            std::string gs = nextToken(fin);
            std::string bs = nextToken(fin);

            if (rs.empty() || gs.empty() || bs.empty()) {
                throw std::runtime_error("Error: not enough pixel data in PPM file");
            }

            pixels[r][c] = {std::stoi(rs), std::stoi(gs), std::stoi(bs)};
        }
    }
}

void Image::save(const std::string& filename) const {
    std::ofstream fout(filename);
    if (!fout) {
        throw std::runtime_error("Error: could not open output file '" + filename + "'");
    }

    fout << "P3\n";
    fout << width() << ' ' << height() << "\n";
    fout << 255 << "\n";

    for (const auto& row : pixels) {
        for (const auto& pixel : row) {
            fout << pixel.r << ' ' << pixel.g << ' ' << pixel.b << ' ';
        }
        fout << "\n";
    }
}

int Image::width() const {
    return pixels.empty() ? 0 : static_cast<int>(pixels[0].size());
}

int Image::height() const {
    return static_cast<int>(pixels.size());
}
