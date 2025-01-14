//
// Created by x on 13/01/2025.
//

#ifndef BMPIMAGEREADER_H
#define BMPIMAGEREADER_H

#include <iostream>
#include "../ImageReader.h"
#include "../../PixelArray.h"

class BmpImageReader : public ImageReader {
    public:
    PixelArray readImage(const std::string &filePath) override;
};



#endif //BMPIMAGEREADER_H
