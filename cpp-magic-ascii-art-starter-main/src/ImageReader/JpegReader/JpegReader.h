//
// Created by Patrik on 15/01/2025.
//

#ifndef JPEGREADER_H
#define JPEGREADER_H
#include <string>
#include <fstream>
#include "../../external/JpegDecoder/JpegDecoder.h"
#include "../IImageReader.h"


class JpegReader: public IImageReader {
    std::ifstream buffer;
public:

    PixelArray readImage(const std::string &filePath) override;
};



#endif //JPEGREADER_H
