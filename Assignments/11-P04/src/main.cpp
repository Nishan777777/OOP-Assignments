#include "Image.h"
#include "Pipeline.h"
#include "Grayscale.h"
#include "Brighten.h"
#include "FlipH.h"
#include "FlipV.h"
#include "Rotate.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: app input.ppm output.ppm [grayscale] [brighten] [fliph] [flipv] [rotate]\n";
        return 1;
    }

    std::string input = argv[1];
    std::string output = argv[2];

    Image image;

    if (!image.loadPPM(input)) {
        std::cout << "Error: Could not load input file.\n";
        return 1;
    }

    Pipeline pipeline;

    Grayscale grayscale;
    Brighten brighten;
    FlipH fliph;
    FlipV flipv;
    Rotate rotate;

    for (int i = 3; i < argc; i++) {
        std::string option = argv[i];

        if (option == "grayscale") {
            pipeline.add(&grayscale);
        } else if (option == "brighten") {
            pipeline.add(&brighten);
        } else if (option == "fliph") {
            pipeline.add(&fliph);
        } else if (option == "flipv") {
            pipeline.add(&flipv);
        } else if (option == "rotate") {
            pipeline.add(&rotate);
        }
    }

    pipeline.run(image);

    if (!image.savePPM(output)) {
        std::cout << "Error: Could not save output file.\n";
        return 1;
    }

    std::cout << "Image saved to " << output << "\n";
    return 0;
}