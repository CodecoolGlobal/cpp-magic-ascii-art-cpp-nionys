//
// Created by Patrik on 13/01/2025.
//

#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include "../PixelArray.h"

class ImageReader {
public:
    virtual ~ImageReader() = default;

    virtual PixelArray readImage(const std::string &filePath, int &width, int &height) = 0;
};

#endif // IMAGEREADER_H
