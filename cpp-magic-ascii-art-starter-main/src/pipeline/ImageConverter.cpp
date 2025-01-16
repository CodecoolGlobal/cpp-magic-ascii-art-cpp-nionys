//
// Created by User on 2025. 01. 15..
//

#include "imageConverter.h"
#include "ImageReader/BmpImageReader/BmpImageReader.h"
#include "ImageReader/IImageReader.h"
#include "ImageReader/JpegReader/JpegReader.h"
#include "ImageReader/PngImageReader/PngImageReader.h"

std::string ImageConverter::convert(const int height, const int width) {
    if (!isLoaded) throw std::runtime_error("state exception");
    const PixelArray<double> grayArray = grayscale.convert(rgbArray);
    std::string asciiArt = asciiArtifier.asciiArtify(grayArray, height, width);
    return asciiArt;
}

std::string ImageConverter::convert() {
    return convert(rgbArray.getHeight(), rgbArray.getWidth());
}

void ImageConverter::changeImageReaderToMatchFile(std::string fileName) {
    size_t extension_index = fileName.find_last_of('.');
    if (extension_index == std::string::npos) {
        throw std::runtime_error("missing file extension");
    }
    const std::string fileExtension = fileName.substr(extension_index + 1);
    delete imageReader;

    if (fileExtension == "bmp") {
        imageReader = new BmpImageReader();
    } else if (fileExtension == "jpg") {
        imageReader = new JpegReader();
    } else if (fileExtension == "png") {
        imageReader = new PngImageReader();
    } else {
        throw std::runtime_error("Unsupported file format: " + fileExtension);
    }

}

void ImageConverter::load(const std::string& imagePath) {
    try {
        changeImageReaderToMatchFile(imagePath);
        rgbArray = imageReader->readImage(imagePath);
        isLoaded = true;

        delete imageReader;
    } catch (std::exception& e) {
        isLoaded = false;
        throw e;
    }
}


