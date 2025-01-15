//
// Created by x on 14/01/2025.
//

#include "PngImageReader.h"
#include "../../external/lodepng/lodepng.h"
#include <iostream>

PixelArray PngImageReader::readImage(const std::string &filePath) {
    std::vector<unsigned char> image;
    unsigned int width, height;
    unsigned error = lodepng::decode(image, width, height, filePath);

    std::cout << image.size() << " " << width << " " << height << std::endl;

    PixelArray pixelArray = PixelArray{static_cast<int>(height), static_cast<int>(width), 3};

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {

        }
    }
    return pixelArray;
}
