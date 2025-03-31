<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

# Magic ASCII Art Converter

<!-- ABOUT THE PROJECT -->
## About The Project

The Magic ASCII Art Converter is a C++ application that transforms images into ASCII representations. It supports multiple image formats, including BMP, PNG, and JPEG, and allows users to customize the output resolution. The tool is designed for developers, artists, and enthusiasts who enjoy experimenting with digital art and creative text-based representations of images.

The project was developed with efficiency and modularity in mind, utilizing object-oriented design principles. It employs various image processing techniques to convert pixel data into grayscale values and map them to corresponding ASCII characters based on brightness intensity.
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Features

- Converts images to ASCII art
- Supports PNG, JPEG, and BMP formats
- Customizable output resolution
- Built using C++ with CMake for easy compilation and installation
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Built With

This section should list any major frameworks/libraries used to bootstrap your project. Leave any add-ons/plugins for the acknowledgements section. Here are a few examples.

[![C++][Cpp]][Cpp-url]
[![CMake][CMake]][CMake-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Prerequisites

Make sure you have the following installed before proceeding:

### CMake (Minimum Version 3.30)

- **Windows**: Download and install CMake from the official site: [https://cmake.org/download/](https://cmake.org/download/)
- **Linux (Ubuntu)**: Install CMake using Snap:
  ```sh
  sudo snap install cmake --classic and ensure `snap` is in your PATH.
  ```
- **Mac**: Install via Homebrew:
  ```sh
  brew install cmake
  ```

### C++ Compiler

Ensure you have a C++17-compatible compiler installed, such as GCC or Clang.

- **Windows**:
  - Install [MinGW](https://www.mingw-w64.org/) and ensure `g++` is in your PATH.
- **Linux (Ubuntu)**:
  ```sh
  sudo apt install g++
  ```
- **Mac**:
  ```sh
  brew install gcc
  ```
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Installation

1. Clone the repository:
   ```sh
   git clone git@github.com:CodecoolGlobal/cpp-magic-ascii-art-cpp-nionys.git
   cd cpp-magic-ascii-art-cpp-nionys
   ```
2. Navigate to the executable directory:
   ```sh
   cd cpp-magic-ascii-art-starter-main/executable
   ```
3. Run CMake to configure the project:
   ```sh
   cmake ../..
   ```
4. Compile the project:
   ```sh
   make
   ```
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Usage

After compilation, the executable will be located in the **`executable`** directory. You can copy paste pictures in bnp, jpg, and png formats in the **`pics`** directory. Run the program with the following arguments:

```sh
./image_to_ascii -img input_image.jpg -target output.txt -width 100 -height 50
```
<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Arguments:

- *`-img`* : Path to the input image
- *`-target`* : Path to the output ASCII file
- *`-width`* : Width of the ASCII output (optional)
- *`-height`* : Height of the ASCII output (optional)

*Example:*
```sh
./image_to_ascii -img sample.png -target ascii_output.txt -width 80 -height 40
```

The ASCII art will be saved to **`results/output.txt`**.
<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Proposed Features
- [ ] **Inverted Mode** – Swap light and dark characters for different effects  
- [ ] **Border & Padding Options** – Add simple borders around ASCII output  
- [ ] **Basic Config File Support** – Save user settings for reuse  
- [ ] **Help Command** – `--help` flag to display available options  
- [ ] **Basic Image Cropping** – Crop an image before converting to ASCII  
- [ ] **Undo/Redo Feature** – Simple way to revert the last operation  

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[CMake]: https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white
[CMake-url]: https://cmake.org/
[Cpp]: https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white
[Cpp-url]: https://isocpp.org/
