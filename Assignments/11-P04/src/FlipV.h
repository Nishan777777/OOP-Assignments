#ifndef FLIPV_H
#define FLIPV_H

#include "Filter.h"

class FlipV : public Filter {
public:
    void apply(Image& image) override;
    std::string name() const override;
};

#endif