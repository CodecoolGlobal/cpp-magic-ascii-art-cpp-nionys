//
// Created by x on 13/01/2025.
//

#include "BmpImageReader.h"
#include "EasyBMP.h"


PixelArray BmpImageReader::readImage(std::string filePath, int &width, int &height) {
    BMP bmp;
    bmp.ReadFromFile(filePath.c_str());
    width = bmp.TellWidth();
    height = bmp.TellHeight();
    PixelArray array(height, width, 3);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            array.setCell(j, i, 0, bmp.GetPixel(i, j).Red);
            array.setCell(j, i, 1, bmp.GetPixel(i, j).Green);
            array.setCell(j, i, 2, bmp.GetPixel(i, j).Blue);
        }
    }

    return  array;
};