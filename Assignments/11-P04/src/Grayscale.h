#ifndef GRAYSCALE_H
#define GRAYSCALE_H

#include "Filter.h"

class Grayscale : public Filter {
public:
    void apply(Image& image) override;
    std::string name() const override;
};

#endif