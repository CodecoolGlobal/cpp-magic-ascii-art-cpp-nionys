//
// Created by Patrik on 13/01/2025.
//

#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <Color.h>

#include "../PixelArray.h"

class IImageReader {
public:
    virtual ~IImageReader() = default;

    virtual PixelArray<Color> readImage(const std::string &filePath) = 0;
};

#endif // IMAGEREADER_H
