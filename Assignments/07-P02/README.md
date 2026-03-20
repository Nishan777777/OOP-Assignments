# Program 2 - Command Line Args Parser

## Build
g++ -std=c++17 -O2 -Wall -Wextra -pedantic main.cpp Args.cpp -o imgtool

## Supported Options

### Flags
- `--grayscale` or `-g`
- `--blur` or `-l`
- `--flipH` or `-h`
- `--flipV` or `-v`

### Options with values
- `--brighten N` or `-b N`
- `--brighten=N`
- `--rotate N` or `-r N`
- `--rotate=N`

## Rules
- brighten must be in `[-255, 255]`
- rotate must be one of `{0, 90, 180, 270}`

## Example Commands

### Valid
- `./imgtool in.png out.png --grayscale --brighten 20 --blur`
- `./imgtool in.png out.png -g -l -b 25 -r 90`
- `./imgtool in.png out.png --brighten=15 --rotate=180`

### Invalid
- `./imgtool in.png`
- `./imgtool in.png out.png --brighten`
- `./imgtool in.png out.png --brighten --blur`
- `./imgtool in.png out.png --rotate 45`
- `./imgtool in.png out.png --graycale`