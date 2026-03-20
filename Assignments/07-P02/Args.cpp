#include "Args.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

void print_usage() {
    std::cout << "Usage: ./imgtool <input_image> <output_image> [options]\n";
}

[[noreturn]] void fail(const std::string& message) {
    std::cerr << "Error: " << message << "\n";
    print_usage();
    throw std::runtime_error(message);
}

bool is_option(const std::string& s) {
    return !s.empty() && s[0] == '-';
}

bool parse_int(const std::string& text, int& value) {
    try {
        std::size_t pos = 0;
        int parsed = std::stoi(text, &pos);
        if (pos != text.size()) {
            return false;
        }
        value = parsed;
        return true;
    } catch (...) {
        return false;
    }
}

std::string require_value(int argc, char* argv[], int& i, const std::string& opt_name) {
    if (i + 1 >= argc) {
        fail(opt_name + " requires an integer value");
    }

    std::string value = argv[++i];

    if (is_option(value)) {
        fail(opt_name + " expected a value but got option " + value);
    }

    return value;
}

void handle_brighten_value(Args& args, const std::string& value_text) {
    int value = 0;
    if (!parse_int(value_text, value)) {
        fail("invalid integer for --brighten: " + value_text);
    }

    if (value < -255 || value > 255) {
        fail("brighten must be in [-255, 255]");
    }

    args.use_brighten = true;
    args.brighten = value;
}

void handle_rotate_value(Args& args, const std::string& value_text) {
    int value = 0;
    if (!parse_int(value_text, value)) {
        fail("invalid integer for --rotate: " + value_text);
    }

    if (!(value == 0 || value == 90 || value == 180 || value == 270)) {
        fail("rotate must be one of {0, 90, 180, 270}");
    }

    args.use_rotate = true;
    args.rotate = value;
}

void handle_long_option(Args& args, const std::string& token, int argc, char* argv[], int& i) {
    std::size_t eq_pos = token.find('=');
    std::string name = token;
    std::string value;

    if (eq_pos != std::string::npos) {
        name = token.substr(0, eq_pos);
        value = token.substr(eq_pos + 1);
    }

    if (name == "--grayscale") {
        args.grayscale = true;
    } else if (name == "--blur") {
        args.blur = true;
    } else if (name == "--flipH") {
        args.flipH = true;
    } else if (name == "--flipV") {
        args.flipV = true;
    } else if (name == "--brighten") {
        if (eq_pos == std::string::npos) {
            value = require_value(argc, argv, i, "--brighten");
        } else if (value.empty()) {
            fail("--brighten requires an integer value");
        }
        handle_brighten_value(args, value);
    } else if (name == "--rotate") {
        if (eq_pos == std::string::npos) {
            value = require_value(argc, argv, i, "--rotate");
        } else if (value.empty()) {
            fail("--rotate requires an integer value");
        }
        handle_rotate_value(args, value);
    } else {
        fail("unknown option " + token);
    }
}

void handle_short_option(Args& args, const std::string& token, int argc, char* argv[], int& i) {
    if (token == "-g") {
        args.grayscale = true;
    } else if (token == "-l") {
        args.blur = true;
    } else if (token == "-h") {
        args.flipH = true;
    } else if (token == "-v") {
        args.flipV = true;
    } else if (token == "-b") {
        std::string value = require_value(argc, argv, i, "--brighten");
        handle_brighten_value(args, value);
    } else if (token == "-r") {
        std::string value = require_value(argc, argv, i, "--rotate");
        handle_rotate_value(args, value);
    } else if (token.size() > 2 && token[0] == '-' && token[1] != '-') {
        for (std::size_t j = 1; j < token.size(); ++j) {
            char c = token[j];
            if (c == 'g') {
                args.grayscale = true;
            } else if (c == 'l') {
                args.blur = true;
            } else if (c == 'h') {
                args.flipH = true;
            } else if (c == 'v') {
                args.flipV = true;
            } else if (c == 'b') {
                fail("grouped short options cannot include -b because it requires a value");
            } else if (c == 'r') {
                fail("grouped short options cannot include -r because it requires a value");
            } else {
                fail("unknown option -" + std::string(1, c));
            }
        }
    } else {
        fail("unknown option " + token);
    }
}

}

Args Args::parse(int argc, char* argv[]) {
    if (argc < 2) {
        fail("missing input file");
    }
    if (argc < 3) {
        fail("missing output file");
    }

    Args args;
    args.input = argv[1];
    args.output = argv[2];

    for (int i = 3; i < argc; ++i) {
        std::string token = argv[i];

        if (!is_option(token)) {
            fail("unexpected extra positional argument: " + token);
        }

        if (token.rfind("--", 0) == 0) {
            handle_long_option(args, token, argc, argv, i);
        } else {
            handle_short_option(args, token, argc, argv, i);
        }
    }

    return args;
}