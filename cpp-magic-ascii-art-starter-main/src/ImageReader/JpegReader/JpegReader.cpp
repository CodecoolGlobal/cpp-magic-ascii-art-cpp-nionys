//
// Created by Patrik on 15/01/2025.
//

#include "JpegReader.h"
#include <sstream>
PixelArray JpegReader::readImage(const std::string &filePath) {
    std::ifstream inputsream = std::ifstream(filePath, std::ios::binary);
    std::stringstream ss;
    ss << inputsream.rdbuf();
    const unsigned char *buffer = reinterpret_cast<const unsigned char *>(ss.str().c_str());
    Jpeg::Decoder jpegDecoder = Jpeg::Decoder(buffer, ss.str().length());
    unsigned char *jpegArray = jpegDecoder.GetImage();
    int width = jpegDecoder.GetWidth();
    int height = jpegDecoder.GetHeight();
    PixelArray array(width, height, 3);
    int a;
    for (int j = 0; j < width; j++) {
        for (int i = 0; i < width; i++) {
            for (int k = 0; k < 3; k++) {
                array.setCell(i, j, k, jpegArray[a++]);
            }
        }
    }
    return array;
}
