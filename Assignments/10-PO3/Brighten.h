#ifndef BRIGHTEN_H
#define BRIGHTEN_H

#include "Filter.h"

class Brighten : public Filter {
private:
    int amount;
    static int clamp(int value);
public:
    explicit Brighten(int amount);
    void apply(Grid& pixels) override;
    std::string name() const override;
};

#endif
