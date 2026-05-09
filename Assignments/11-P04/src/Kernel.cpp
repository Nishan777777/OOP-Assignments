#include "Kernel.h"

Kernel::Kernel() : data(1, std::vector<double>(1, 1.0)) {}

Kernel::Kernel(int size) : data(size, std::vector<double>(size, 0.0)) {}

int Kernel::size() const {
    return data.size();
}

double Kernel::at(int row, int col) const {
    return data[row][col];
}

void Kernel::set(int row, int col, double value) {
    data[row][col] = value;
}

Kernel Kernel::identity(int size) {
    Kernel k(size);
    int middle = size / 2;
    k.set(middle, middle, 1.0);
    return k;
}