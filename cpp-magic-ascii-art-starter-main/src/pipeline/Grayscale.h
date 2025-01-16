//
// Created by User on 2025. 01. 14..
//

#ifndef GRAYSCALE_H
#define GRAYSCALE_H
#include <Color.h>

#include "../PixelArray.h"

class Grayscale {
private:
    inline static double WEIGHT_RED{0.3};
    inline static double WEIGHT_GREEN{0.59};
    inline static double WEIGHT_BLUE{0.11};

public:
    [[nodiscard]] static PixelArray<double> convert(const PixelArray<Color> &array) ;
private:
    static double convertToGrayValue(Color color);
};

#endif //GRAYSCALE_H
