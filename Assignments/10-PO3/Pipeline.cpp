#include "Pipeline.h"

#include <iostream>

Pipeline::~Pipeline() {
    for (Filter* f : filters) {
        delete f;
    }
}

void Pipeline::add(Filter* f) {
    filters.push_back(f);
}

void Pipeline::run(Grid& pixels) {
    for (Filter* f : filters) {
        f->apply(pixels);
    }
}

void Pipeline::printSteps() const {
    std::cout << "FILTERS : ";
    if (filters.empty()) {
        std::cout << "none";
    } else {
        for (size_t i = 0; i < filters.size(); ++i) {
            std::cout << filters[i]->name();
            if (i + 1 < filters.size()) {
                std::cout << " -> ";
            }
        }
    }
    std::cout << '\n';
}
