#ifndef KERNEL_H
#define KERNEL_H

#include <vector>

class Kernel {
private:
    std::vector<std::vector<double>> data;

public:
    Kernel();
    Kernel(int size);

    int size() const;
    double at(int row, int col) const;
    void set(int row, int col, double value);

    static Kernel identity(int size);
};

#endif