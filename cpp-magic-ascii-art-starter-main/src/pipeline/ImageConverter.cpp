//
// Created by User on 2025. 01. 15..
//

#include "imageConverter.h"
#include "ImageReader/IImageReader.h"
#include "ImageReader/BmpImageReader/BmpImageReader.h"
#include "ImageReader/JpegReader/JpegReader.h"

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
        std::string fileExtension = imagePath.substr(imagePath.find_last_of(".") + 1);
        IImageReader* imageReader = nullptr;

        if (fileExtension == "bmp") {
            imageReader = new BmpImageReader();
        } else if (fileExtension == "jpg") {
            imageReader = new JpegReader();
        } /*else if (fileExtension == "png") {
            imageReader = new PngImageReader();
        }*/ else {
            throw std::runtime_error("Unsupported file format: " + fileExtension);
        }

        rgbArray = imageReader->readImage(imagePath);
        isLoaded = true;

        delete imageReader;
    } catch (std::exception& e) {
        isLoaded = false;
        throw e;
    }
}


