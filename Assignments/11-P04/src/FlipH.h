#ifndef FLIPH_H
#define FLIPH_H

#include "Filter.h"

class FlipH : public Filter {
public:
    void apply(Image& image) override;
    std::string name() const override;
};

#endif