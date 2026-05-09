#ifndef KERNELFILTER_H
#define KERNELFILTER_H

#include "Filter.h"
#include "Kernel.h"

class KernelFilter : public Filter {
private:
    Kernel kernel;

public:
    KernelFilter();
    KernelFilter(const Kernel& k);

    void apply(Image& image) override;
    std::string name() const override;
};

#endif