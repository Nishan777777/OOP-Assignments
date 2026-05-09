# OOP-Assignments

Collection of Object Oriented Programming assignments completed in C++.

---

# Assignments

## 06-PO1 — Program 1: Image Tool

Simple image processing tool using stb_image and stb_image_write libraries.

### Features
- Load image
- Convert image to grayscale
- Save processed image

### Build
```bash
g++ -std=c++17 -O2 source1.cpp -o imgtool.exe
```

### Run
```bash
./imgtool.exe input.png output.png
```

---

## 07-PO2 — Program 2: Command Line Args Parser

Image processing application with command-line argument parsing.

### Supported Filters
- Grayscale
- Blur
- Flip Horizontal
- Flip Vertical
- Brighten
- Rotate

### Build
```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic main.cpp Args.cpp -o imgtool
```

### Example
```bash
./imgtool input.ppm output.ppm --grayscale
```

---

## 10-PO3 — Program 3: Image Filter Pipeline

Pipeline-based image filtering system using Object Oriented Programming concepts.

### Features
- Multiple filters
- Sequential filter pipeline
- PPM image support

### Build
```bash
g++ -std=c++17 *.cpp -o imgtool
```

### Example Commands
```bash
./imgtool test1.ppm out1.ppm --grayscale

./imgtool test1.ppm out2.ppm --brighten 40 --flipH

./imgtool test2.ppm out3.ppm --grayscale --brighten 30 --rotate 90
```

---

## 11-P04 — Program 4: Advanced Image Pipeline

Advanced image processing framework using inheritance, polymorphism, and reusable filters.

### Filters Included
- Grayscale
- Brighten
- Flip Horizontal
- Flip Vertical
- Rotate
- Kernel Filter

### Build
```bash
g++ src/*.cpp -I src -o app
```

### Run
```bash
./app src/test1.ppm src/output.ppm grayscale
```

### Example
```bash
./app src/test1.ppm src/output.ppm grayscale brighten
```

---

# Author

Nishan Dhakal  
MSU Texas  
Computer Science
