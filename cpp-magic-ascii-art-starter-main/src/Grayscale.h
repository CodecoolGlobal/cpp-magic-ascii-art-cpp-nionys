//
// Created by User on 2025. 01. 14..
//

#ifndef GRAYSCALE_H
#define GRAYSCALE_H
#include <string>

#include "PixelArray.h"

class Grayscale {
private:
    inline static double WEIGHT_RED{0.3};
    inline static double WEIGHT_GREEN{0.59};
    inline static double WEIGHT_BLUE{0.11};

    const std::string characterSet;

public:
    explicit Grayscale(std::string characterSet): characterSet(std::move(characterSet)) {}
    [[nodiscard]] PixelArray convert(const PixelArray &array) const;
private:
    static double convertToGrayValue(const unsigned char &red, const unsigned char &green, const unsigned char &blue);
    [[nodiscard]] char getCharByGrayscaleValue(const double &value) const;
};

#endif //GRAYSCALE_H
