#include "KernelFilter.h"

KernelFilter::KernelFilter() : kernel(Kernel::identity(1)) {}

KernelFilter::KernelFilter(const Kernel& k) : kernel(k) {}

void KernelFilter::apply(Image& image) {
    // Simple placeholder filter
}

std::string KernelFilter::name() const {
    return "KernelFilter";
}