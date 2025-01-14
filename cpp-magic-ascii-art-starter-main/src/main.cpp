//
// Created by Patrik on 13/01/2025.
//
#include <filesystem>

#include <iostream>
#include <utility>

#include "Grayscale.h"
#include "PixelArray.h"
#include "./ImageReader/BmpImageReader/BmpImageReader.h"

using namespace std;


int main(int argc, char **argv) {
    cout << "Hello World!" << endl;

    BmpImageReader bmpImageReader;

    Grayscale gs{"@#8&o:*. "};
    PixelArray array = bmpImageReader.readImage("../pics/test2.bmp");
    PixelArray grayArray = gs.convert(array);
    for (int r = 0; r < grayArray.height; r++) {
        for (int c = 0; c < grayArray.width; c++) {
            std::cout << grayArray.getCell(r, c, 1);
        }
        cout << endl;
    }

}
