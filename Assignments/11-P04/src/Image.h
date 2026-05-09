#ifndef IMAGE_H
#define IMAGE_H

#include "Color.h"
#include <vector>
#include <string>

class Image {
private:
    int width_;
    int height_;
    std::vector<std::vector<Color>> pixels_;

public:
    Image();
    Image(int width, int height);

    int width() const;
    int height() const;

    Color& at(int x, int y);
    const Color& at(int x, int y) const;

    bool loadPPM(const std::string& filename);
    bool savePPM(const std::string& filename) const;
};

#endif