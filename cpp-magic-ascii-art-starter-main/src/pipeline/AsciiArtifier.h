//
// Created by User on 2025. 01. 15..
//

#ifndef ASCIIIFIER_H
#define ASCIIIFIER_H
#include <stdexcept>
#include <string>
#include <utility>

#include "PixelArray.h"


class AsciiArtifier {
private:
    struct Rect {
        const double left, right;
        const double top, bottom;

        Rect(double left, double right, double top, double bottom): left(left), right(right), top(top), bottom(bottom) {
            if (left > right || top > bottom) throw std::invalid_argument("invalid Rect");
        }
        double getWidth() const { return right - left; }
        double getHeight() const { return bottom - top; }
        double getArea() const { return getWidth() * getHeight(); }
    };
private:
    std::string characters;
public:
    explicit AsciiArtifier(std::string characters): characters(std::move(characters)) {};

    std::string asciiArtify(const PixelArray<double> &array, unsigned int height, unsigned int width);

    std::string asciiArtify(const PixelArray<double> &array) const;

private:
    [[nodiscard]] static double calculateAreaAverage(const PixelArray<double> &array, Rect rect) ;
    [[nodiscard]] char lookUpAsciiChar(const double &value) const;

};
#endif //ASCIIIFIER_H
