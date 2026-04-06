#ifndef FILTER_H
#define FILTER_H

#include <string>
#include <vector>

struct Pixel {
    int r;
    int g;
    int b;
};

using Row = std::vector<Pixel>;
using Grid = std::vector<Row>;

class Filter {
public:
    virtual void apply(Grid& pixels) = 0;
    virtual std::string name() const = 0;
    virtual ~Filter() = default;
};

#endif
