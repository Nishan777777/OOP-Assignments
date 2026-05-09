#include "Image.h"
#include <fstream>

Image::Image() : width_(0), height_(0) {}

Image::Image(int width, int height)
    : width_(width), height_(height),
      pixels_(height, std::vector<Color>(width)) {}

int Image::width() const {
    return width_;
}

int Image::height() const {
    return height_;
}

Color& Image::at(int x, int y) {
    return pixels_[y][x];
}

const Color& Image::at(int x, int y) const {
    return pixels_[y][x];
}

bool Image::loadPPM(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return false;

    std::string type;
    int maxColor;

    in >> type;
    if (type != "P3") return false;

    in >> width_ >> height_ >> maxColor;

    pixels_ = std::vector<std::vector<Color>>(height_, std::vector<Color>(width_));

    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            int r, g, b;
            in >> r >> g >> b;
            pixels_[y][x] = Color(r, g, b);
        }
    }

    return true;
}

bool Image::savePPM(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) return false;

    out << "P3\n";
    out << width_ << " " << height_ << "\n";
    out << "255\n";

    for (int y = 0; y < height_; y++) {
        for (int x = 0; x < width_; x++) {
            const Color& c = pixels_[y][x];
            out << c.r << " " << c.g << " " << c.b << " ";
        }
        out << "\n";
    }

    return true;
}