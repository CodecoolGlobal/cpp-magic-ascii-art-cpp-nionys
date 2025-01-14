//
// Created by Patrik on 13/01/2025.
//
#include <filesystem>

#include <iostream>
#include <vector>

#include "PixelArray.h"
#include "ImageReader/BmpImageReader/BmpImageReader.h"

using namespace std;

class AsciiColor {
public:
    const char character;
    const double min;
    const double max;

    AsciiColor(const char character, const double min, const double max): character(character), min(min), max(max) {
    }
};

class Grayscale {
    vector<AsciiColor> asciiColors{};

public:
    Grayscale(string characterSet) {
        for (int i = 0; i < characterSet.length(); i++) {
            double maxValue = 0.3 * 255 + 0.59 * 255 + 0.11 * 255;
            double stepSize = maxValue / characterSet.length();
            asciiColors.emplace_back(characterSet[i], i * stepSize, (i + 1) * stepSize);
        }
    }

    const char getCharByGrayscaleValue(const double value) const {
        for (const AsciiColor asciiColor: asciiColors) {
            if (value <= asciiColor.max and value >= asciiColor.min) {
                return asciiColor.character;
            }
        }
        throw std::runtime_error("Grayscale value out of range" + std::to_string(value));
    }

    void convert(const PixelArray &array) {
        /* GrayscaleValue = 0.3 * R + 0.59 * G + 0.11 * B */
        PixelArray grayArray{array.height, array.width, 1};
        for (int r = 0; r < array.height; r++) {
            for (int c = 0; c < array.width; c++) {
                double grayPixelValue = 0;
                const int red = array.getCell(r, c, 0);
                const int green = array.getCell(r, c, 1);
                const int blue = array.getCell(r, c, 2);
                grayPixelValue = 0.3 * red + 0.59 * green + 0.11 * blue;
                char asciiChar = getCharByGrayscaleValue(grayPixelValue);
                std::cout << asciiChar << std::endl;
            }
        }
    }
};

int main(int argc, char **argv) {
    cout << "Hello World!" << endl;
    int width;
    int height;

    BmpImageReader bmpImageReader;

    PixelArray array = bmpImageReader.readImage("../pics/test2.bmp", width, height);
    // for (int i = 0; i < height; i++) {
    //     for (int j = 0; j < width; j++) {
    //         for (int k = 0; k < 3; k++) {
    //             std::cout << +array.getCell(i, j, k) << " ";
    //         }
    //         cout << ",";
    //     }
    //     cout << endl;
    // }

    Grayscale gs{"@#8&o:*. "};
    gs.convert(array);
}
