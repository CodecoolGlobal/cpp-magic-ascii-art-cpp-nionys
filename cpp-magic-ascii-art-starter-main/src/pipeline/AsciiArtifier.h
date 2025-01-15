//
// Created by User on 2025. 01. 15..
//

#ifndef ASCIIIFIER_H
#define ASCIIIFIER_H
#include <string>
#include <utility>

#include "PixelArray.h"


class AsciiArtifier {
private:
    std::string characters;
public:
    explicit AsciiArtifier(std::string characters): characters(std::move(characters)) {};

    std::string asciiArtify(const PixelArray<double> &array, unsigned int height, unsigned int width);
private:
    [[nodiscard]] char getCharByGrayscaleValue(const double &value) const;

};
#endif //ASCIIIFIER_H
