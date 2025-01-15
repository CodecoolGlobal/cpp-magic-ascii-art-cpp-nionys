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

    PixelArray pixelArray = PixelArray{static_cast<int>(height), static_cast<int>(width), 3};

    int channelCount = 0;
    for (int row = 0; row < pixelArray.height; row++) {
        for (int col = 0; col < pixelArray.width; col++) {
            pixelArray.setCell(row, col, 0, image[channelCount]);
            pixelArray.setCell(row, col, 1, image[channelCount + 1]);
            pixelArray.setCell(row, col, 2, image[channelCount + 2]);
            channelCount += 4;
        }
    }

    return pixelArray;
}
