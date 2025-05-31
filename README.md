![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![MLX42](https://img.shields.io/badge/MLX42-OpenGL%2FGLFW-blue)

# 🌀 Fractal Visualizer

**Fract-ol** is a fractal visualizer, written in C using [MLX42](https://github.com/codam-coding-college/MLX42), a simple cross-platform graphics library running on GLFW and OpenGL.  
The project is a part of 42 school curriculum

## ✨ Features

- Interactive rendering of:
  - Mandelbrot set
  - Julia set
  - Burning Ship fractal
- Real-time mouse interaction
- Smooth zooming and panning
- Dynamic color shifting

## 📸 Preview

<div style="display: flex; gap: 10px; align-items: center;">
  <img src="./screenshot1.png" width="200" />
  <img src="./screenshot2.png" width="200" />
  <img src="./screenshot3.png" width="200" />
</div>

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
  <strong><em>Iteration Formula:</em></strong><br>
    z<sub>n+1</sub> = z<sub>n</sub><sup>2</sup> + C,&nbsp;&nbsp; z<sub>0</sub> = C,&nbsp;&nbsp; C = a + b<em>i</em>
  </code>
</div>

## ⚙️ Requirements

- macOS or Linux
- Dependencies:
  - `cmake`
  - `glfw`
  - `OpenGL`

## 🧰 Installation

Clone the repo and build:

```bash
git clone https://github.com/usvapel/fract-ol.git
cd fract-ol
make
