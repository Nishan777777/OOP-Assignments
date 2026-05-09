#ifndef FILTER_H
#define FILTER_H

#include "Image.h"
#include <string>

class Filter {
public:
    virtual void apply(Image& image) = 0;
    virtual std::string name() const = 0;
    virtual ~Filter() {}
};

#endif