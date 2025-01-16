//
// Created by x on 14/01/2025.
//

#include "PngImageReader.h"
#include "../../external/lodepng/lodepng.h"
#include <iostream>

PixelArray <Color> PngImageReader::readImage(const std::string &filePath) {
    std::vector<unsigned char> image;
    unsigned int width, height;
    lodepng::decode(image, width, height, filePath);

    PixelArray <Color> pixelArray = PixelArray <Color>{static_cast<int>(height), static_cast<int>(width)};

    int channelCount = 0;
    for (int row = 0; row < pixelArray.getHeight(); row++) {
        for (int col = 0; col < pixelArray.getWidth(); col++) {
            pixelArray.setCell(row, col, {
                image[channelCount],
                image[channelCount+1],
                image[channelCount+2]
            });
            channelCount += 4;
        }
    }
    return pixelArray;
}
