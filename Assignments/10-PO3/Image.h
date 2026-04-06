#ifndef IMAGE_H
#define IMAGE_H

#include "Filter.h"

#include <string>

class Image {
public:
    Grid pixels;
    void load(const std::string& filename);
    void save(const std::string& filename) const;
    int width() const;
    int height() const;
};

#endif
