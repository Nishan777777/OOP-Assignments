# Program 3 - Image Filter Pipeline

## Build
Use g++ in VS Code terminal:

```bash
g++ -std=c++17 *.cpp -o imgtool
```

## Run
```bash
./imgtool input.ppm output.ppm [options]
```

## 5 Example Commands
```bash
./imgtool test1.ppm out1.ppm --grayscale
./imgtool test1.ppm out2.ppm --brighten 40 --flipH
./imgtool test2.ppm out3.ppm --grayscale --brighten 30 --blur --rotate 90
./imgtool test3.ppm out4.ppm -g -b 20 -l
./imgtool test2.ppm out5.ppm --flipV --rotate 270
```

## Ordering Justification
I used `std::vector<std::string> order` inside `Args`.

This is the cleanest choice because:
1. `Args` still handles command-line parsing.
2. `Pipeline` still handles filter execution.
3. The exact order typed by the user is preserved.

That matters because:
- `--grayscale --brighten 50` is not always the same design decision as `--brighten 50 --grayscale`.
- The assignment says pipeline order matters.

So when parsing each option, I push its operation name into `order`, and then `main.cpp` builds the pipeline in that same order.

## Files Included
- Args.h / Args.cpp
- Filter.h
- Grayscale.h / Grayscale.cpp
- Brighten.h / Brighten.cpp
- FlipH.h / FlipH.cpp
- FlipV.h / FlipV.cpp
- Blur.h / Blur.cpp
- Rotate.h / Rotate.cpp
- Pipeline.h / Pipeline.cpp
- Image.h / Image.cpp
- main.cpp
- test1.ppm
- test2.ppm
- test3.ppm
