//
// Created by x on 14/01/2025.
//

#ifndef PNGIMAGEREADER_H
#define PNGIMAGEREADER_H
#include <string>

#include "../ImageReader.h"
#include "../../PixelArray.h"

class PngImageReader : public ImageReader {
    public:
public:
    PixelArray readImage(const std::string &filePath) override;
};



#endif //PNGIMAGEREADER_H
