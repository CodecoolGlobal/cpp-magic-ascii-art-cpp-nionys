//
// Created by User on 2025. 01. 15..
//

#include "imageConverter.h"
#include "ImageReader/IImageReader.h"
#include "ImageReader/BmpImageReader/BmpImageReader.h"

std::string ImageConverter::convert(const int height, const int width) {
    if (!isLoaded) throw std::runtime_error("state exception");
    const PixelArray<double> grayArray = grayscale.convert(rgbArray);
    std::string asciiArt = asciiArtifier.asciiArtify(grayArray, height, width);
    return asciiArt;
}

std::string ImageConverter::convert() {
    return convert(rgbArray.getHeight(), rgbArray.getWidth());
}

void ImageConverter::load(std::string imagePath) {
    try {
        IImageReader* imageReader= new BmpImageReader();
        rgbArray = imageReader->readImage(imagePath);
        isLoaded = true;
    } catch (std::exception& e) {
        isLoaded = false;
        throw e;
    }
}
