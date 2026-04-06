#ifndef ARGS_H
#define ARGS_H

#include <string>
#include <vector>

class Args {
public:
    std::string input;
    std::string output;

    bool grayscale = false;
    bool blur = false;
    bool flipH = false;
    bool flipV = false;

    bool hasBrighten = false;
    int brighten = 0;

    bool hasRotate = false;
    int rotate = 0;

    std::vector<std::string> order;

    static Args parse(int argc, char* argv[]);
    static void printUsage();
};

#endif
