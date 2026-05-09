---
id: 11-P04
name: 11-P04
title: Program 4 - Advanced Image Pipeline
description: 'Advanced image processing pipeline using OOP concepts'
category: Assignment
date_assigned: 2026-05-01
date_due: 2026-05-08
resources: []
---

# Program 4 - Advanced Image Pipeline

This assignment implements an image processing pipeline using Object Oriented Programming concepts in C++.

## Features

- Grayscale filter
- Brighten filter
- Flip horizontal
- Flip vertical
- Rotate filter
- Kernel filter

## Build

```bash
g++ src/*.cpp -I src -o app
```

## Run

```bash
./app src/test1.ppm src/output.ppm grayscale
```