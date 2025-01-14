//
// Created by x on 14/01/2025.
//

#include "PngImageReader.h"
#include "lodepng.h"

PixelArray PngImageReader::readImage(const std::string &filePath) {
    return *new PixelArray{0, 0, 0};
}
