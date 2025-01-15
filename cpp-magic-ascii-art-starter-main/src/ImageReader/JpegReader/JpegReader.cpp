//
// Created by Patrik on 15/01/2025.
//

#include "JpegReader.h"
#include <sstream>

#include "external/JpegDecoder/JpegDecoder.h"

PixelArray<Color> JpegReader::readImage(const std::string &filePath) {
    std::ifstream inputsream = std::ifstream(filePath, std::ios::binary);
    std::stringstream ss;
    ss << inputsream.rdbuf();
    const unsigned char *buffer = reinterpret_cast<const unsigned char *>(ss.str().c_str());
    Jpeg::Decoder jpegDecoder = Jpeg::Decoder(buffer, ss.str().length());
    unsigned char *jpegArray = jpegDecoder.GetImage();
    int width = jpegDecoder.GetWidth();
    int height = jpegDecoder.GetHeight();
    PixelArray<Color> array(height, width);
    int a{0};
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            array.setCell(r, c, Color(
                jpegArray[a++],
                jpegArray[a++],
                jpegArray[a++]
                ));
        }
    }
    return array;
}
