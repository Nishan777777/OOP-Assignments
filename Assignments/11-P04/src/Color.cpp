#include "Color.h"

Color::Color() : r(0), g(0), b(0) {}

Color::Color(int red, int green, int blue) : r(red), g(green), b(blue) {}

Color Color::operator+(const Color& other) const {
    return Color(r + other.r, g + other.g, b + other.b);
}

Color Color::operator*(double factor) const {
    return Color(r * factor, g * factor, b * factor);
}