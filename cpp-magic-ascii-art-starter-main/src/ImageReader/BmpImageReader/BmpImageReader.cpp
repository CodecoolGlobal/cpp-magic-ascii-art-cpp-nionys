//
// Created by x on 13/01/2025.
//

#include "BmpImageReader.h"
#include "EasyBMP.h"


PixelArray<Color> BmpImageReader::readImage(const std::string &filePath) {
    BMP bmp;
    bool result = bmp.ReadFromFile(filePath.c_str());
    if (!result) {
        throw std::runtime_error("Error reading BMP file: "+filePath);
    }
    PixelArray<Color> array(bmp.TellHeight(), bmp.TellWidth());

    for (int r = 0; r < array.getHeight(); r++) {
        for (int c = 0; c < array.getWidth(); c++) {
            Color color{
                bmp.GetPixel(c, r).Red,
                bmp.GetPixel(c, r).Green,
                bmp.GetPixel(c, r).Blue,
            };
            array.setCell(r, c, color);
        }
    }
    return  array;
};