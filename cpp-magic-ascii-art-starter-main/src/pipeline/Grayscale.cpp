//
// Created by User on 2025. 01. 14..
//

#include "Grayscale.h"

#include <cmath>
#include <Color.h>
#include <stdexcept>

double Grayscale::convertToGrayValue(const Color color) {
    return WEIGHT_RED * color.getRed() + WEIGHT_GREEN * color.getGreen() + WEIGHT_BLUE * color.getBlue();
}

// ReSharper disable once CppMemberFunctionMayBeStatic
PixelArray<double> Grayscale::convert(const PixelArray<Color> &array) const {
    PixelArray<double> grayArray{array.getHeight(), array.getWidth()};
    for (int r = 0; r < grayArray.getHeight(); r++) {
        for (int c = 0; c < grayArray.getWidth(); c++) {
            double grayPixelValue = 0;
            grayPixelValue = convertToGrayValue(array.getCell(r, c));
            grayArray.setCell(r, c, grayPixelValue);
        }
    }
    return grayArray;
}
