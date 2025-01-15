//
// Created by x on 13/01/2025.
//

#include "BmpImageReader.h"
#include "../../external/EasyBMP_1.06/EasyBMP.h"

PixelArray BmpImageReader::readImage(const std::string &filePath) {
    BMP bmp;
    bmp.ReadFromFile(filePath.c_str());
    PixelArray array(bmp.TellHeight(), bmp.TellWidth(), 3);

    for (int r = 0; r < array.height; r++) {
        for (int c = 0; c < array.width; c++) {
            if (c==1) {
                std::cout << "row: " << r << " col: " << c  << " pixel: " << +bmp.GetPixel(c, r).Red << " " << +bmp.GetPixel(c, r).Blue << std::endl;
            }
            array.setCell(r, c, 0, bmp.GetPixel(c, r).Red);
            array.setCell(r, c, 1, bmp.GetPixel(c, r).Green);
            array.setCell(r, c, 2, bmp.GetPixel(c, r).Blue);
        }
    }
    return  array;
};