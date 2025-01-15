#include "AsciiArtifier.h"

#include <fstream>
#include <sstream>

#include "PixelArray.h"

std::string AsciiArtifier::asciiArtify(const PixelArray<double>& array, unsigned int height, unsigned int width) {
    std::stringstream ss;
    for (int r = 0; r < array.getHeight(); r++) {
        for (int c = 0; c < array.getWidth(); c++) {
            ss << getCharByGrayscaleValue(array.getCell(r, c));
        }
        ss << std::endl;
    }
    return ss.str();
}

char AsciiArtifier::getCharByGrayscaleValue(const double &value) const {
    constexpr double maxValue = 255;
    int idx = value / maxValue * characters.size();
    if (idx >= characters.size()) {
        idx = characters.size() - 1;
    }
    return characters[idx];
}
