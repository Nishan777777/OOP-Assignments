#include "Args.h"

#include <iostream>
#include <stdexcept>
#include <vector>

int main(int argc, char* argv[]) {
    try {
        Args args = Args::parse(argc, argv);

        std::cout << "INPUT  : " << args.input << "\n";
        std::cout << "OUTPUT : " << args.output << "\n";

        std::vector<std::string> flags;
        if (args.grayscale) flags.push_back("grayscale");
        if (args.blur) flags.push_back("blur");
        if (args.flipH) flags.push_back("flipH");
        if (args.flipV) flags.push_back("flipV");

        std::cout << "FLAGS  :";
        if (flags.empty()) {
            std::cout << " none";
        } else {
            for (const std::string& flag : flags) {
                std::cout << " " << flag;
            }
        }
        std::cout << "\n";

        bool any_params = args.use_brighten || args.use_rotate;
        std::cout << "PARAMS :";
        if (!any_params) {
            std::cout << " none";
        } else {
            bool first = true;
            if (args.use_brighten) {
                std::cout << " brighten=" << args.brighten;
                first = false;
            }
            if (args.use_rotate) {
                if (!first) {
                    std::cout << " ";
                }
                std::cout << "rotate=" << args.rotate;
            }
        }
        std::cout << "\n";

        return 0;
    } catch (const std::exception&) {
        return 1;
    }
}