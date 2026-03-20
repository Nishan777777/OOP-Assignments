#ifndef ARGS_H
#define ARGS_H

#include <string>

struct Args {
    std::string input;
    std::string output;

    bool grayscale = false;
    bool blur = false;
    bool flipH = false;
    bool flipV = false;

    bool use_brighten = false;
    int brighten = 0;

    bool use_rotate = false;
    int rotate = 0;

    static Args parse(int argc, char* argv[]);
};

#endif