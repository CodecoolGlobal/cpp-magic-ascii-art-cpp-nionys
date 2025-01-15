//
// Created by User on 2025. 01. 15..
//

#ifndef IMAGECONVERTER_H
#define IMAGECONVERTER_H
#include <Color.h>
#include <string>

#include "AsciiArtifier.h"
#include "Grayscale.h"
#include "PixelArray.h"
#include "ImageReader/IImageReader.h"

class ImageConverter {
private:
    bool isLoaded{false};
    IImageReader* imageReader = nullptr;
    Grayscale grayscale{};
    AsciiArtifier asciiArtifier{"@#8&o:*. "};

    PixelArray<Color> rgbArray{0, 0};
public:
    void load(std::string imagePath);
    std::string convert(int height, int width);
    std::string convert();
};
#endif //IMAGECONVERTER_H
