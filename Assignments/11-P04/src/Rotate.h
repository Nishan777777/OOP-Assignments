#ifndef ROTATE_H
#define ROTATE_H

#include "Filter.h"

class Rotate : public Filter {
public:
    void apply(Image& image) override;
    std::string name() const override;
};

#endif