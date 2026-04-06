#ifndef PIPELINE_H
#define PIPELINE_H

#include "Filter.h"

#include <vector>

class Pipeline {
public:
    ~Pipeline();
    void add(Filter* f);
    void run(Grid& pixels);
    void printSteps() const;
private:
    std::vector<Filter*> filters;
};

#endif
