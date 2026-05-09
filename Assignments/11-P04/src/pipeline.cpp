#include "Pipeline.h"

void Pipeline::add(Filter* filter) {
    filters.push_back(filter);
}

void Pipeline::run(Image& image) {
    for (Filter* filter : filters) {
        filter->apply(image);
    }
}