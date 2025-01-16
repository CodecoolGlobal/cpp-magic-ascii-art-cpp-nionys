//
// Created by x on 14/01/2025.
//

#ifndef PNGIMAGEREADER_H
#define PNGIMAGEREADER_H
#include <string>

#include "../IImageReader.h"
#include "../../PixelArray.h"

class PngImageReader : public IImageReader {
    public:
public:
    PixelArray <Color> readImage(const std::string &filePath) override;

};



#endif //PNGIMAGEREADER_H
