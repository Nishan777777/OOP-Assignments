#ifndef BRIGHTEN_H
#define BRIGHTEN_H

#include "Filter.h"

class Brighten : public Filter {
public:
    void apply(Image& image) override;
    std::string name() const override;
};

#endif