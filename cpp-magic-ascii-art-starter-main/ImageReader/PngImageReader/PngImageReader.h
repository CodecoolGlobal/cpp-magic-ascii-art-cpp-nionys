//
// Created by x on 14/01/2025.
//

#ifndef PNGIMAGEREADER_H
#define PNGIMAGEREADER_H
#include <string>

#include "../ImageReader.h"

class PngImageReader : public ImageReader {
    public:
    PixelArray readImage(std::string filePath, int &width, int &height) override;

};



#endif //PNGIMAGEREADER_H
