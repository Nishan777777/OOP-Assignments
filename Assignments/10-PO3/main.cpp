#include "Args.h"
#include "Blur.h"
#include "Brighten.h"
#include "FlipH.h"
#include "FlipV.h"
#include "Grayscale.h"
#include "Image.h"
#include "Pipeline.h"
#include "Rotate.h"

#include <iostream>

int main(int argc, char* argv[]) {
    try {
        Args args = Args::parse(argc, argv);

        Image img;
        img.load(args.input);

        Pipeline pipeline;
        for (const std::string& op : args.order) {
            if (op == "grayscale") pipeline.add(new Grayscale());
            else if (op == "brighten") pipeline.add(new Brighten(args.brighten));
            else if (op == "blur") pipeline.add(new Blur());
            else if (op == "flipH") pipeline.add(new FlipH());
            else if (op == "flipV") pipeline.add(new FlipV());
            else if (op == "rotate") pipeline.add(new Rotate(args.rotate));
        }

        std::cout << "INPUT   : " << args.input << '\n';
        std::cout << "OUTPUT  : " << args.output << '\n';
        pipeline.printSteps();

        pipeline.run(img.pixels);
        img.save(args.output);

        std::cout << "Done. Output written to " << args.output << '\n';
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
