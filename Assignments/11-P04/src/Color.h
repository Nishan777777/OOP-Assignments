#ifndef COLOR_H
#define COLOR_H

class Color {
public:
    int r, g, b;

    Color();
    Color(int red, int green, int blue);

    Color operator+(const Color& other) const;
    Color operator*(double factor) const;
};

#endif