## Table of Contents
- [Features](#features)
- [Preview](#preview)
- [Fractal Math](#fractal-math)
- [Requirements](#requirements)
- [Installation](#installation)

# Fractal Visualizer

<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/c/c-original.svg" alt="C" width="30"/> ![MLX42](https://img.shields.io/badge/MLX42-C%20Graphics-blue?style=flat-square)

**Fract-ol** is a fractal visualizer, written in C using [**MLX42**](https://github.com/codam-coding-college/MLX42), a simple cross-platform graphics library running on **GLFW** and **OpenGL**.  
This project was developed as part of the 42 school curriculum.

## Features

- This application supports real-time rendering and interaction with a selection of well-known fractals:
  - Mandelbrot set
  - Julia set
  - Burning Ship fractal
- Interactive features:
  - Real-time mouse interaction
  - Smooth zooming and panning
  - Dynamic color shifting

## Preview

<p align="center">
  <img src="./images/Mandelbrot.png" width="500"/>
  <img src="./images/Burningship.png" width="500"/>
  <img src="./images/Julia.png" width="500"/>
</p>


## Fractal Math
<div style="
  background-color: #f6f8fa;
  padding: 20px 24px;
  border-left: 6px solid #00599C;
  font-family: 'Segoe UI', 'Roboto', 'Helvetica Neue', sans-serif;
  font-size: 16px;
  color: #1a1a1a;
  line-height: 1.6;
  margin-top: 12px;
  box-shadow: 0 2px 4px rgba(0, 0, 0, 0.05);
">
  <strong><em>Iteration Formula</em></strong><br>
</div>

The core of each fractal lies in an iterative function applied to each pixel mapped onto the complex plane. For the **Mandelbrot set**, the formula is:

![Mandelbrot Equation](https://latex.codecogs.com/png.image?\dpi{150}&space;\color{White}z_{n+1}=z_n^2+C,\quad&space;z_0=C,\quad&space;C=a+bi)

<div align="center">
  <img src="https://latex.codecogs.com/svg.latex?\dpi{150}&space;z_{n+1}=z_n^2+C,\quad&space;z_0=C,\quad&space;C=a+bi" />
</div>

For the **Burning Ship fractal**, a slight modification is made: the real and imaginary components of the complex number are converted to their **absolute** values before squaring at each iteration, resulting in its characteristic shape.

## Requirements

- Linux
- Dependencies:
  - [`CMake`](https://cmake.org/) – Cross-platform build system generator.
  - [`GLFW`](https://www.glfw.org/) – Window and input library for OpenGL / Vulkan.
  - [`OpenGL`](https://www.opengl.org/) – Cross-platform 2D / 3D graphics API.

## Installation

Clone the repo and build:

```bash
git clone https://github.com/usvapel/fract-ol.git
cd fract-ol
make
