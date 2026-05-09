#ifndef PIPELINE_H
#define PIPELINE_H

#include "Filter.h"
#include <vector>

class Pipeline {
private:
    std::vector<Filter*> filters;

public:
    void add(Filter* filter);
    void run(Image& image);
};

#endif