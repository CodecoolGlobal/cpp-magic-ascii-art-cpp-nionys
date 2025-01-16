#include "AsciiArtifier.h"

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

#include "PixelArray.h"

std::string AsciiArtifier::asciiArtify(const PixelArray<double> &array, unsigned int targetVerticalResolution,
                                       unsigned int targetHorizontalResolution) {
    std::stringstream ss;
    const double areaHeight = static_cast<double>(array.getHeight()) / targetVerticalResolution;
    const double areaWidth = static_cast<double>(array.getWidth()) / targetHorizontalResolution;
    for (int areaRowIndex = 0; areaRowIndex < targetVerticalResolution; areaRowIndex++) {
        for (int areaColumnIndex = 0; areaColumnIndex < targetHorizontalResolution; areaColumnIndex++) {
            double left = areaColumnIndex * areaWidth;
            double right = (areaColumnIndex + 1) *areaWidth;
            double top = areaRowIndex *areaHeight;
            double bottom = (areaRowIndex + 1) *areaHeight;
            ss << lookUpAsciiChar(calculateAreaAverage(array, {left, right, top, bottom}));
        }
        ss << std::endl;
    }
    return ss.str();
}

std::string AsciiArtifier::asciiArtify(const PixelArray<double> &array) const {
    std::stringstream ss;
    for (int rowIndex = 0; rowIndex < array.getHeight(); rowIndex++) {
        for (int columnIndex = 0; columnIndex < array.getWidth(); columnIndex++) {
            ss << lookUpAsciiChar(array.getCell(rowIndex, columnIndex));
        }
        ss << std::endl;
    }
    return ss.str();
}

inline double calculateIntervalIntersection(const double lb1, const double ub1, const double lb2, const double ub2) {
    const double lowerBound = std::max(lb1, lb2);
    const double upperBound = std::min(ub1, ub2);
    if (lowerBound > upperBound) return 0;
    return upperBound-lowerBound;
}

double AsciiArtifier::calculateAreaAverage(const PixelArray<double> &array, const Rect rect) {
    double sum = 0.0;
    for (int i = floor(rect.top); i < ceil(rect.bottom); i++) {
#define PIXEL_TOP i
#define PIXEL_BOTTOM (i+1)
        double verticalWeight = calculateIntervalIntersection(PIXEL_TOP, PIXEL_BOTTOM, rect.top, rect.bottom);
        for (int j = floor(rect.left); j < ceil(rect.right); j++) {
#define PIXEL_LEFT j
#define PIXEL_RIGHT (j+1)
            double horizontalWeight = calculateIntervalIntersection(PIXEL_LEFT, PIXEL_RIGHT, rect.left, rect.right);
            sum += verticalWeight * horizontalWeight * array.getCell(i, j);
        }
    }
#undef PIXEL_TOP, PIXEL_BOTTOM, PIXEL_LEFT, PIXEL_RIGHT
    return sum / (rect.getArea());
}

char AsciiArtifier::lookUpAsciiChar(const double &value) const {
    constexpr double maxValue = 255;
    int idx = value / maxValue * characters.size();
    if (idx >= characters.size()) {
        idx = characters.size() - 1;
    }
    return characters[idx];
}
