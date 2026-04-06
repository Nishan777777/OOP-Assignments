#include "Args.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

namespace {
    bool isInteger(const std::string& s) {
        if (s.empty()) return false;
        size_t start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
        if (start == s.size()) return false;
        for (size_t i = start; i < s.size(); ++i) {
            if (s[i] < '0' || s[i] > '9') return false;
        }
        return true;
    }

    int parseInt(const std::string& s, const std::string& what) {
        if (!isInteger(s)) {
            throw std::runtime_error("Error: " + what + " must be an integer");
        }
        return std::stoi(s);
    }
}

Args Args::parse(int argc, char* argv[]) {
    if (argc < 3) {
        printUsage();
        throw std::runtime_error("Error: missing required arguments");
    }

    Args args;
    args.input = argv[1];
    args.output = argv[2];

    for (int i = 3; i < argc; ++i) {
        std::string opt = argv[i];

        if (opt == "--grayscale" || opt == "-g") {
            args.grayscale = true;
            args.order.push_back("grayscale");
        }
        else if (opt == "--blur" || opt == "-l") {
            args.blur = true;
            args.order.push_back("blur");
        }
        else if (opt == "--flipH" || opt == "-H") {
            args.flipH = true;
            args.order.push_back("flipH");
        }
        else if (opt == "--flipV" || opt == "-V") {
            args.flipV = true;
            args.order.push_back("flipV");
        }
        else if (opt == "--brighten" || opt == "-b") {
            if (i + 1 >= argc) {
                throw std::runtime_error("Error: missing value for brighten");
            }
            int value = parseInt(argv[++i], "brighten");
            if (value < -255 || value > 255) {
                throw std::runtime_error("Error: brighten must be in [-255, 255]");
            }
            args.hasBrighten = true;
            args.brighten = value;
            args.order.push_back("brighten");
        }
        else if (opt == "--rotate" || opt == "-r") {
            if (i + 1 >= argc) {
                throw std::runtime_error("Error: missing value for rotate");
            }
            int value = parseInt(argv[++i], "rotate");
            if (value != 0 && value != 90 && value != 180 && value != 270) {
                throw std::runtime_error("Error: rotate must be one of {0, 90, 180, 270}");
            }
            args.hasRotate = true;
            args.rotate = value;
            args.order.push_back("rotate");
        }
        else {
            throw std::runtime_error("Error: unknown option '" + opt + "'");
        }
    }

    return args;
}

void Args::printUsage() {
    std::cout << "Usage: ./imgtool <input_image> <output_image> [options]\n"
              << "Options:\n"
              << "  --grayscale, -g\n"
              << "  --brighten N, -b N   (N in [-255, 255])\n"
              << "  --blur, -l\n"
              << "  --flipH, -H\n"
              << "  --flipV, -V\n"
              << "  --rotate N, -r N     (N in {0, 90, 180, 270})\n";
}
