//
// Created by User on 2025. 01. 14..
//

#include "Grayscale.h"

#include <cmath>
#include <stdexcept>

double Grayscale::convertToGrayValue(const unsigned char &red, const unsigned char &green, const unsigned char &blue) {
    return WEIGHT_RED * red + WEIGHT_GREEN * green + WEIGHT_BLUE * blue;
}

char Grayscale::getCharByGrayscaleValue(const double &value) const {
    const double maxValue = convertToGrayValue(255, 255, 255);
    int idx = value / maxValue * characterSet.size();
    if (idx >= characterSet.size()) {
        idx = characterSet.size() - 1;
    }
    return characterSet[idx];
}

PixelArray Grayscale::convert(const PixelArray &array) const {
    PixelArray grayArray{array.height, array.width, 1};
    for (int r = 0; r < array.height; r++) {
        for (int c = 0; c < array.width; c++) {
            double grayPixelValue = 0;
            grayPixelValue = convertToGrayValue(
                array.getCell(r, c, 0),
                array.getCell(r, c, 1),
                array.getCell(r, c, 2)
            );
            const char asciiChar = getCharByGrayscaleValue(grayPixelValue);
            grayArray.setCell(r, c, 0, asciiChar);
        }
    }
    return grayArray;
}
